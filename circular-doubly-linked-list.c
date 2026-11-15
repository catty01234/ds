// 6. To write a C program to implement a Circular Doubly Linked List that supports
// insertion at the beginning and end, and displays all nodes.


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

struct node* getnode() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    return newnode;
}

void insertBeg(int x) {
    struct node *newnode = getnode();

    newnode->data = x;

    if (head == NULL) {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
    }
    else {
        struct node *last = head->prev;

        newnode->next = head;
        newnode->prev = last;

        last->next = newnode;
        head->prev = newnode;

        head = newnode;
    }
}

void insertEnd(int x) {
    struct node *newnode = getnode();

    newnode->data = x;

    if (head == NULL) {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
    }
    else {
        struct node *last = head->prev;

        newnode->next = head;
        newnode->prev = last;

        last->next = newnode;
        head->prev = newnode;
    }
}

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    printf("Circular Doubly Linked List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    int choice, x;

    do {
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insertBeg(x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &x);
                insertEnd(x);
                break;

            case 3:
                display();
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