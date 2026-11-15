// 20.Write C programs to implement Hash Table using Open Addressing (Linear
// Probing) and Perform insertion, searching, and deletion operations.


#include <stdio.h>

#define SIZE 10

int table[SIZE];
int status[SIZE] = {0};

int hash(int key) {
    return key % SIZE;
}

void insert(int x) {
    int index = hash(x);
    int i;

    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (status[pos] != 1) {
            table[pos] = x;
            status[pos] = 1;
            printf("Element inserted\n");
            return;
        }
    }

    printf("Hash Table is Full\n");
}

void search(int x) {
    int index = hash(x);
    int i;

    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (status[pos] == 0)
            break;

        if (status[pos] == 1 && table[pos] == x) {
            printf("Element found at index %d\n", pos);
            return;
        }
    }

    printf("Element not found\n");
}

void delete(int x) {
    int index = hash(x);
    int i;

    for (i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (status[pos] == 0)
            break;

        if (status[pos] == 1 && table[pos] == x) {
            status[pos] = 2;
            printf("Element deleted\n");
            return;
        }
    }

    printf("Element not found\n");
}

void display() {
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d: ", i);

        if (status[i] == 1)
            printf("%d\n", table[i]);
        else if (status[i] == 2)
            printf("Deleted\n");
        else
            printf("Empty\n");
    }
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                printf("Enter element to search: ");
                scanf("%d", &x);
                search(x);
                break;

            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &x);
                delete(x);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}