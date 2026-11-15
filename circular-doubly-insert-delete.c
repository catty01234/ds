// 7. To write a C program to implement a Circular Doubly Linked List that performs
// deletion from beginning and end, insertion between nodes, deletion based on a
// condition, and displays all nodes.


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

void deleteBeg() {
    struct node *temp;

    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    temp = head;

    if (head->next == head)
        head = NULL;
    else {
        struct node *last = head->prev;
        head = head->next;
        head->prev = last;
        last->next = head;
    }

    free(temp);
}

void deleteEnd() {
    struct node *temp;

    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    temp = head->prev;

    if (head->next == head)
        head = NULL;
    else {
        struct node *last = temp->prev;
        last->next = head;
        head->prev = last;
    }

    free(temp);
}

void insertBetween(int x, int pos) {
    struct node *newnode, *temp;
    int i;

    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    if (pos < 1) {
        printf("Invalid Position\n");
        return;
    }

    if (pos == 1) {
        struct node *last = head->prev;

        newnode = getnode();
        newnode->data = x;

        newnode->next = head;
        newnode->prev = last;

        last->next = newnode;
        head->prev = newnode;

        head = newnode;
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (i != pos - 1) {
        printf("Invalid Position\n");
        return;
    }

    newnode = getnode();
    newnode->data = x;

    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void deleteCondition(int x) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    do {
        if (temp->data == x) {
            if (temp->next == temp)
                head = NULL;
            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head)
                    head = temp->next;
            }

            free(temp);
            printf("Node Deleted\n");
            return;
        }

        temp = temp->next;

    } while (temp != head);

    printf("Element Not Found\n");
}

void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is Empty\n");
        return;
    }

    printf("List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    int choice, x, pos;

    do {
        printf("\n1. Insert at End");
        printf("\n2. Delete from Beginning");
        printf("\n3. Delete from End");
        printf("\n4. Insert Between Nodes");
        printf("\n5. Delete by Value");
        printf("\n6. Display");
        printf("\n7. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insertEnd(x);
                break;

            case 2:
                deleteBeg();
                break;

            case 3:
                deleteEnd();
                break;

            case 4:
                printf("Enter element and position: ");
                scanf("%d%d", &x, &pos);
                insertBetween(x, pos);
                break;

            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &x);
                deleteCondition(x);
                break;

            case 6:
                display();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 7);

    return 0;
}