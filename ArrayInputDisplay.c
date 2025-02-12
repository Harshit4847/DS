#include <stdio.h>

int main() {
    int arr[10], n;

    printf("Enter the number of elements you want (max 10):\n");
    scanf("%d", &n);

    if (n > 10) {
        printf("Array can hold a maximum of 10 elements.\n");
        return
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements inside array are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n")

    return 0;
}
