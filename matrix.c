#include<stdio.h>

typedef struct Matrix{
	int rows;
	int columns;
	float num[5][5];
}matrix;

matrix readMatrix();
void printMatrix(matrix);
int* countLeadingZeros(matrix);
matrix sortByLeadingZeros(matrix, int*);
matrix swapRows(matrix, int, int);
matrix swapColumns(matrix, int, int);
matrix transpose(matrix);
matrix addMatrix(matrix, matrix);
matrix subMatrix(matrix, matrix);
matrix mulMatrix(matrix, matrix);
matrix zeroMatrix(int, int);

int main(){
	matrix originalMatrix;
	originalMatrix = readMatrix();
	printMatrix(originalMatrix);

	matrix transformedMatrix;
	transformedMatrix = originalMatrix;
	//printMatrix(transformedMatrix);

	int* leadingZeros;
	leadingZeros = countLeadingZeros(transformedMatrix);
	
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