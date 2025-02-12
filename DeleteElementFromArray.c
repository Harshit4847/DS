#include <stdio.h>

void deleteElement(int arr[], int *n, int position) {
    if (position >= *n || position < 0) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
}

void displayArray(int arr[], int n) {
    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[10], n, position;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &position);

    deleteElement(arr, &n, position);

    displayArray(arr, n);

    return 0;
}
