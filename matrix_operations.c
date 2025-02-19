#include <stdio.h>

#define MAX 10  


void inputMatrix(int mat[MAX][MAX], int row, int col) {
    printf("Enter elements of the matrix (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mat[i][j]);
        }
    }
}


void printMatrix(int mat[MAX][MAX], int row, int col) {
    printf("Matrix (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}


void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}


void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int row1, col1, row2, col2;
    int choice;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &row1, &col1);
    inputMatrix(A, row1, col1);

    printf("Choose operation:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:  
            printf("Enter rows and columns for Matrix B: ");
            scanf("%d %d", &row2, &col2);
            if (row1 != row2 || col1 != col2) {
                printf("Addition not possible! Matrices should be of same dimensions.\n");
                return 0;
            }
            inputMatrix(B, row2, col2);
            addMatrices(A, B, result, row1, col1);
            printf("Resultant Matrix (Addition):\n");
            printMatrix(result, row1, col1);
            break;

        case 2:  
            printf("Enter rows and columns for Matrix B: ");
            scanf("%d %d", &row2, &col2);
            if (row1 != row2 || col1 != col2) {
                printf("Subtraction not possible! Matrices should be of same dimensions.\n");
                return 0;
            }
            inputMatrix(B, row2, col2);
            subtractMatrices(A, B, result, row1, col1);
            printf("Resultant Matrix (Subtraction):\n");
            printMatrix(result, row1, col1);
            break;

        case 3:  
            printf("Enter rows and columns for Matrix B: ");
            scanf("%d %d", &row2, &col2);
            if (col1 != row2) {
                printf("Multiplication not possible! Columns of A should be equal to rows of B.\n");
                return 0;
            }
            inputMatrix(B, row2, col2);
            multiplyMatrices(A, B, result, row1, col1, col2);
            printf("Resultant Matrix (Multiplication):\n");
            printMatrix(result, row1, col2);
            break;

        case 4:  
            transposeMatrix(A, result, row1, col1);
            printf("Transpose of the given matrix:\n");
            printMatrix(result, col1, row1);
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
    }

    return 0;
}
