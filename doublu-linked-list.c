// 5. Write a program to implement a Doubly Linked List with 10 float elements,
// allowing insertion and deletion from both ends.



#include <stdio.h>
#include <stdlib.h>

struct node {
    float data;
    struct node *prev, *next;
};

struct node *head = NULL, *tail = NULL;

struct node* getnode() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    return newnode;
}

void insertBeg(float x) {
    struct node *newnode = getnode();

    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = head;

    if (head == NULL)
        head = tail = newnode;
    else {
        head->prev = newnode;
        head = newnode;
    }
}

void insertEnd(float x) {
    struct node *newnode = getnode();

    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = tail;

    if (tail == NULL)
        head = tail = newnode;
    else {
        tail->next = newnode;
        tail = newnode;
    }
}

void deleteBeg() {
    struct node *temp;

    if (head == NULL)
        printf("List is Empty\n");
    else {
        temp = head;
        head = head->next;

        if (head == NULL)
            tail = NULL;
        else
            head->prev = NULL;

        printf("Deleted: %.2f\n", temp->data);
        free(temp);
    }
}

void deleteEnd() {
    struct node *temp;

    if (tail == NULL)
        printf("List is Empty\n");
    else {
        temp = tail;
        tail = tail->prev;

        if (tail == NULL)
            head = NULL;
        else
            tail->next = NULL;

        printf("Deleted: %.2f\n", temp->data);
        free(temp);
    }
}

void display() {
    struct node *temp = head;

    if (head == NULL)
        printf("List is Empty\n");
    else {
        printf("List: ");
        while (temp != NULL) {
            printf("%.2f ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int i, choice;
    float x;

    printf("Enter 10 float elements:\n");

    for (i = 0; i < 10; i++) {
        scanf("%f", &x);
        insertEnd(x);
    }

    do {
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Delete from Beginning");
        printf("\n4. Delete from End");
        printf("\n5. Display");
        printf("\n6. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%f", &x);
                insertBeg(x);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%f", &x);
                insertEnd(x);
                break;

            case 3:
                deleteBeg();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 6);

    return 0;
}