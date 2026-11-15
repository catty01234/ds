// 15.Write a C program to implement Quick Sort to sort a list of numbers in ascending
// order and display the sorted output.

#include <stdio.h>

#define MAX 100

void quickSort(int a[], int low, int high) {
    int i, j, pivot, temp;

    if (low < high) {
        pivot = a[low];
        i = low + 1;
        j = high;

        while (i <= j) {
            while (i <= high && a[i] <= pivot)
                i++;

            while (a[j] > pivot)
                j--;

            if (i < j) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[low];
        a[low] = a[j];
        a[j] = temp;

        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
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

    quickSort(a, 0, n - 1);

    display(a, n);

    return 0;
}