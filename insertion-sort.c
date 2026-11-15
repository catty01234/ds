// 13.Write a C program to implement Insertion Sort to arrange a list of numbers in
// ascending order and display the sorted output.



#include <stdio.h>
#define MAX 100

void insertionSort(int a[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void display(int a[], int n) {
    int i;

    printf("Sorted Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main() {
    int a[MAX], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    insertionSort(a, n);
    display(a, n);

    return 0;
}