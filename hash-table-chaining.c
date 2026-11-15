// 19.Write C programs to implement Hash Table using Chaining (Separate Linked
// Lists) and Perform insertion, searching, and deletion operations.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node *next;
};

struct Node *table[SIZE] = {NULL};

int hash(int key) {
    return key % SIZE;
}

void insert(int x) {
    int index = hash(x);
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = x;
    newnode->next = table[index];
    table[index] = newnode;

    printf("Element inserted\n");
}

void search(int x) {
    int index = hash(x);
    struct Node *temp = table[index];

    while (temp != NULL) {
        if (temp->data == x) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }

    printf("Element not found\n");
}

void delete(int x) {
    int index = hash(x);
    struct Node *temp = table[index];
    struct Node *prev = NULL;

    while (temp != NULL) {
        if (temp->data == x) {
            if (prev == NULL)
                table[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Element deleted\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Element not found\n");
}

void display() {
    int i;
    struct Node *temp;

    for (i = 0; i < SIZE; i++) {
        printf("%d: ", i);

        temp = table[i];

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
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