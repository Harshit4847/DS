#include <stdio.h>

void concatenateArrays(int arr1[], int n1, int arr2[], int n2, int result[]) {
    for (int i = 0; i < n1; i++) {
        result[i] = arr1[i];
    }

    for (int i = 0; i < n2; i++) {
        result[n1 + i] = arr2[i];
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr1[100], arr2[100], result[200], n1, n2;

    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);

    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);

    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    concatenateArrays(arr1, n1, arr2, n2, result);

    printf("Concatenated Array: ");
    displayArray(result, n1 + n2);

    return 0;
}
