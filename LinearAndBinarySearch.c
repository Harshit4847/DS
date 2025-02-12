#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; // Return -1 if the element is not found
}

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100], n, key, choice;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are: ");
    displayArray(arr, n);

    printf("\nChoose search method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result = -1;

    if (choice == 1) {
        result = linearSearch(arr, n, key);
        if (result != -1) {
            printf("Element %d found at index %d using Linear Search.\n", key, result);
        } else {
            printf("Element %d not found using Linear Search.\n", key);
        }
    } else if (choice == 2) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        result = binarySearch(arr, n, key);
        if (result != -1) {
            printf("Element %d found at index %d using Binary Search.\n", key, result);
        } else {
            printf("Element %d not found using Binary Search.\n", key);
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
