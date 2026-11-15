// 4. Write a program in C to implement a Singly Linked List with 5 integer elements.
// Perform insertion, deletion, and traversal operations.



#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* getnode() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    return newnode;
}

void insert(int x) {
    struct node *newnode, *temp;

    newnode = getnode();
    newnode->data = x;
    newnode->next = NULL;

    if (head == NULL)
        head = newnode;
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
    }
}

void delete() {
    struct node *temp;

    if (head == NULL)
        printf("List is Empty\n");
    else {
        temp = head;
        head = head->next;

        printf("Deleted: %d\n", temp->data);
        free(temp);
    }
}

void traverse() {
    struct node *temp = head;

    if (head == NULL)
        printf("List is Empty\n");
    else {
        printf("Linked List: ");

        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\n");
    }
}

int main() {
    int i, x, choice;

    printf("Enter 5 elements:\n");

    for (i = 0; i < 5; i++) {
        scanf("%d", &x);
        insert(x);
    }

    do {
        printf("\n1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insert(x);
                break;

            case 2:
                delete();
                break;

            case 3:
                traverse();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 4);

    return 0;
}