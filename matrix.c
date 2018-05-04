#include<stdio.h>
#include<math.h>

typedef struct Matrix{
	int rows;
	int columns;
	float num[5][5];
}matrix;

typedef struct Vector{
	int flag;	//0 - doesn't matter, 1 - row, 2 - column
	int dim;
	int num[5];
}vector;

typedef struct MetaMatrix{
	matrix mat;
	int isSquare;
	int determinant;
	int rank;
}meta;

matrix readMatrix();
void printMatrix(matrix);
matrix swapRows(matrix, int, int);
matrix swapColumns(matrix, int, int);
matrix transpose(matrix);
matrix addMatrix(matrix, matrix);
matrix subMatrix(matrix, matrix);
matrix mulMatrix(matrix, matrix);
matrix zeroMatrix(int, int);
matrix identityMatrix(int);
int isVector(matrix);
int isRowVector(matrix);
int isColumnVector(matrix);
int isSquareMatrix(matrix);
int isZeroMatrix(matrix);
float traceOfMatrix(matrix);
float normOfMatrix(matrix);
matrix removeRowOfMatrix(matrix, int);
matrix removeColumnOfMatrix(matrix, int);
matrix partMatrix(matrix, int, int);
float minor(matrix, int, int);
int determinant(matrix);
int* countLeadingZeros(matrix);
matrix sortByLeadingZeros(matrix, int*);
int rankOfMatrix(matrix);
matrix makeLeadingEntryOne(matrix, int*);


int main(){
	//matrix originalMatrix;
	//originalMatrix = readMatrix();
	//printMatrix(originalMatrix);

	matrix transformedMatrix;
	//transformedMatrix = originalMatrix;
	transformedMatrix = identityMatrix(4);
	printMatrix(transformedMatrix);
	//transformedMatrix= removeRowOfMatrix(transformedMatrix, 3);
	//printMatrix(transformedMatrix);
	//transformedMatrix= removeColumnOfMatrix(transformedMatrix, 0);
	//printMatrix(transformedMatrix);
	//transformedMatrix= partMatrix(transformedMatrix, 1, 2);
	//printMatrix(transformedMatrix);

	/*
	int* leadingZeros;
	leadingZeros = countLeadingZeros(transformedMatrix);
	*/
	//printf("%f\n", traceOfMatrix(transformedMatrix));
	//printf("%f\n", normOfMatrix(transformedMatrix));
	//printf("%d", rankOfMatrix(transformedMatrix));
	//printf("%d", isZeroMatrix(transformedMatrix));
	
	/*
	transformedMatrix = identityMatrix(4);
	printMatrix(transformedMatrix);

	if(isSquareMatrix(transformedMatrix)){
		printf("Square\n");
	}else{
		printf("Not Square\n");
	}
	/*

	/*
	transformedMatrix = identityMatrix(4);
	printMatrix(transformedMatrix);
	*/

	/*
	transformedMatrix = transpose(originalMatrix);
	printMatrix(transformedMatrix);
	*/
	
	/*
	transformedMatrix = sortByLeadingZeros(transformedMatrix, leadingZeros);
	printMatrix(transformedMatrix);
	
	/*
	transformedMatrix = swapRows(transformedMatrix, 1, 2);
	printMatrix(transformedMatrix);
	*/

	/*
	int i;
	for(i = 0;i < transformedMatrix.rows;i++){
		printf("%d\t", *(leadingZeros + i));
	}
	*/
}

//I/O functions
matrix readMatrix(){
	matrix mat;
	printf("Enter the number of rows : ");
	scanf("%d", &mat.rows);
	printf("Enter the number of columns : ");
	scanf("%d", &mat.columns);
	printf("Enter the elements\n");
	int i, j;
	for(i = 0;i < mat.rows;i++){
		for(j = 0;j < mat.columns;j++){
			scanf("%f", &mat.num[i][j]);
		}
	}
	return mat;
}

void printMatrix(matrix mat){
	printf("No. of rows : %d\n", mat.rows);
	printf("No. of columns : %d\n", mat.columns);
	int i, j;
	for(i = 0;i < mat.rows;i++){
		for(j = 0;j < mat.columns;j++){
			printf("%0.0f\t", mat.num[i][j]);
		}
		printf("\n");
	}
}

matrix swapRows(matrix mat, int m, int n){
	int i, temp;
	for(i = 0;i < mat.columns;i++){
		temp = *(mat.num[m - 1] + i);
		*(mat.num[m - 1] + i) = *(mat.num[n - 1] + i);
		*(mat.num[n - 1] + i) = temp;
	}
	return mat;
}

matrix swapColumns(matrix mat, int m, int n){
	int i, temp;
	for(i = 0;i < mat.rows;i++){
		temp = *(mat.num[i] + m - 1);
		*(mat.num[i] + m - 1) = *(mat.num[i] + n - 1);
		*(mat.num[i] + n - 1) = temp;
	}
	return mat;
}

matrix transpose(matrix mat){
	int i, j;
	matrix transMatrix;
	transMatrix.rows = mat.columns;
	transMatrix.columns = mat.rows;
	for(i = 0;i < transMatrix.rows;i++){
		for(j = 0;j < transMatrix.columns;j++){
			transMatrix.num[i][j] = mat.num[j][i];
		}
	}
	return transMatrix;
}

//Arithmetic operations
matrix addMatrix(matrix mat1, matrix mat2){
	if(mat1.rows == mat2.rows && mat1.columns == mat2.columns){
		printf("Addition possible");
		int i, j;
		matrix mat;
		mat.rows = mat1.rows;
		mat.columns = mat1.columns;
		for(i = 0;i < mat1.rows;i++){
			for(j = 0;j < mat1.columns;j++){
				mat.num[i][j] = mat1.num[i][j] + mat2.num[i][j];
			}
		}
		return mat;
	}else{
		printf("Can not add two matrices of different orders\n");
		//Some exception handling mech
	}
}

matrix subMatrix(matrix mat1, matrix mat2){
	if(mat1.rows == mat2.rows && mat1.columns == mat2.columns){
		printf("Subtraction possible");
		int i, j;
		matrix mat;
		mat.rows = mat1.rows;
		mat.columns = mat1.columns;
		for(i = 0;i < mat1.rows;i++){
			for(j = 0;j < mat1.columns;j++){
				mat.num[i][j] = mat1.num[i][j] - mat2.num[i][j];
			}
		}
		return mat;
	}else{
		printf("Can not subtract two matrices of different orders\n");
		//Some exception handling mech
	}
}

matrix mulMatrix(matrix mat1, matrix mat2){
	if(mat1.columns == mat2.rows){
		printf("Multiplication possible");
		int i, j, k;
		matrix mat;
		mat = zeroMatrix(mat1.rows, mat2.columns);
		//mat.rows = mat1.rows;
		//mat.columns = mat2.columns;
		for(i = 0;i < mat1.rows;i++){
			for(j = 0;j < mat2.columns;j++){
				//mat.num[i][j] = 0;
				for(k = 0;k < mat1.columns;k++){
					mat.num[i][j] += mat1.num[i][k] * mat2.num[k][j];
				}
			}
		}
		return mat;
	}else{
		printf("Can not multiply two matrices of such orders\n");
		//Some exception handling mech
	}
}

//Special matrices
matrix zeroMatrix(int m, int n){
	matrix mat;
	mat.rows = m;
	mat.columns = n;
	int i, j;
	for(i = 0;i < m;i++){
		for(j = 0;j < n;j++){
			mat.num[i][j] = 0;
		}
	}
	return mat;
}

matrix identityMatrix(int m){
	matrix mat;
	mat = zeroMatrix(m, m);
	int i;
	for(i = 0;i < m;i++){
		mat.num[i][i] = 1;
	}
	return mat;
}

//Check speciality
int isVector(matrix mat){
	if((mat.rows == 1) || (mat.columns == 1)){
		return 1;
	}else{
		return 0;
	}
}

int isRowVector(matrix mat){
	if(mat.rows == 1){
		return 1;
	}else{
		return 0;
	}
}

int isColumnVector(matrix mat){
	if(mat.columns == 1){
		return 1;
	}else{
		return 0;
	}
}

int isSquareMatrix(matrix mat){
	if(mat.rows == mat.columns){
		return 1;
	}else{
		return 0;
	}
}

int isZeroMatrix(matrix mat){
	int flag = 0;
	int i, j;
	for(i = 0;i < mat.rows;i++){
		for(j = 0;j < mat.columns;j++){
			if(mat.num[i][j] != 0){
				flag = 1;
			}
		}
	}
	(flag == 0) ? (flag = 1) : (flag = 0);
	return flag;
}

float traceOfMatrix(matrix mat){
	if(isSquareMatrix(mat)){
		int i, j;
		float sum = 0;
		for(i = 0;i < mat.rows;i++){
			sum += mat.num[i][i];
		}
		return sum;
	}else{
		printf("Can't find trace for non square matrices\n");
		//Some exception handling mech
	}
}

float normOfMatrix(matrix mat){
	int i, j;
	float sum = 0;
	for(i = 0;i < mat.rows;i++){
		for(j = 0;j < mat.columns;j++){
			sum += pow(mat.num[i][j], 2);
		}
	}
	return sqrt(sum);
}

//Determinant related functions
//Check performance differences(theoretical & practical) of below 2 logic
matrix removeRowOfMatrix(matrix mat, int m){
	int i, j;
	matrix transMatrix;
	transMatrix.rows = mat.rows - 1;
	transMatrix.columns = mat.columns;
	for(i = 0;i < transMatrix.rows;i++){
		if(i < m){
			for(j = 0;j < transMatrix.columns;j++){
				transMatrix.num[i][j] = mat.num[i][j];
			}
		}else if(i >= m){
			for(j = 0;j < transMatrix.columns;j++){
				transMatrix.num[i][j] = mat.num[i + 1][j];
			}
		}
	}
	return transMatrix;
}

matrix removeColumnOfMatrix(matrix mat, int m){
	int i, j;
	matrix transMatrix;
	transMatrix.rows = mat.rows;
	transMatrix.columns = mat.columns - 1;
	for(i = 0;i < transMatrix.columns;i++){
		for(j = 0;j < transMatrix.rows;j++){
			if(i < m){
				transMatrix.num[j][i] = mat.num[j][i];
			}else if(i >= m){
				transMatrix.num[j][i] = mat.num[j][i + 1];
			}
		}
	}
	return transMatrix;
}

matrix partMatrix(matrix mat, int m, int n){
	mat = removeRowOfMatrix(mat, m);
	mat = removeColumnOfMatrix(mat, n);
	return mat;
}

//Not yet working
/*float minor(matrix mat, int m, int n){
	matrix transMatrix;
	float det = 0;
	transMatrix = mat;
	if(transMatrix.rows == 1){
		return transMatrix.num[0][0];	//base case
	}
	else if(transMatrix.rows == 2){
		return ((transMatrix.num[0][0] * transMatrix.num[1][1]) - (transMatrix.num[0][1] * transMatrix.num[1][0]));
	}else{
		int p, q, r, s;
		det = 0;
      	for(j1=0;j1<n;j1++){
         	for(i=0;i<n-1;i++)
        		m[i] = malloc((n-1)*sizeof(double));
         	for(i=1;i<n;i++){
            	j2 = 0;
            	for(j=0;j<n;j++){
            		if (j == j1)
                		continue;
               		m[i-1][j2] = a[i][j];
               		j2++;
               	}
            }
        det += pow(-1.0,1.0+j1+1.0) * a[0][j1] * Determinant(m,n-1);
      }
	}
}

int determinant(matrix mat){
	matrix transMatrix;
	transMatrix = mat;
	if(isSquareMatrix(transMatrix)){
		if(transMatrix.rows == 1){
			return 1;//temporary solution
		}
	}else{
		printf("Non square matrices do not have determinants\n");
		return 0;
	}
}*/

//Rank related functions
//Not yet working
int* countLeadingZeros(matrix mat){
	int i, j;
	static int zeros[5] = {0,0,0,0,0};
	for(i = 0;i < mat.rows;i++){
		j = 0;
		while(mat.num[i][j] == 0){
			zeros[i]++;
			j++;
		}
	}
	return zeros;
}

matrix sortByLeadingZeros(matrix mat, int* zeros){
	int i, j;
	for(i = 0;i < mat.rows - 1;i++){
		for(j = (i + 1);j < mat.rows;j++){
			if(*(zeros + i) > *(zeros + j)){
				mat = swapRows(mat, i, j);
			}
		}
	}
	return mat;
}

matrix makeLeadingEntryOne(matrix mat, int* leadingZeros){
	int i, j;
	int* pivot;
	for(i = 0;i < mat.rows;i++){
		//*(pivot + i) = mat.num[i][*(leadingZeros + i)];
		//int j;
		j = *(leadingZeros + i);
		*(pivot + i) = mat.num[i][j];
	}
	for(i = 0;i < mat.rows;i++){
		for(j = *(leadingZeros + i);j < mat.columns;j++){
			mat.num[i][j] /=  *(pivot + i);
		}
	}
}

int rankOfMatrix(matrix mat){
	int i;
	int rank = 0;
	//for(i = 0;i < mat.rows;i++){
		printf("1\n");
		printMatrix(mat);
		int* leadingZeros = countLeadingZeros(mat);
		for(rank = 0;rank < mat.rows;rank++){
			printf("%d\n", *(leadingZeros + i));
		}
		printf("2\n");
		printMatrix(mat);
		//mat = makeLeadingEntryOne(mat, leadingZeros);
		printf("3\n");
		printMatrix(mat);
		//mat = sortByLeadingZeros(mat, leadingZeros);
		printf("4\n");
		printMatrix(mat);
	//}
	return rank;
}