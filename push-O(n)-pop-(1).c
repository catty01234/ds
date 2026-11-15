
// 9. Write a C program to implement a Stack using two Queues such that the Push
// operation runs in linear time (O(n)) and the Pop operation runs in constant
// time (O(1)).
// Display the contents of the stack after each operation


#include <stdio.h>
#define MAX 100

int q1[MAX], q2[MAX];
int f1 = 0, r1 = -1;
int f2 = 0, r2 = -1;

void push(int x) {
    int i;

    q2[++r2] = x;

    while (f1 <= r1)
        q2[++r2] = q1[f1++];

    f1 = 0;
    r1 = -1;

    for (i = 0; i <= r2; i++)
        q1[++r1] = q2[i];

    f2 = 0;
    r2 = -1;
}

int pop() {
    if (r1 == -1)
        return -1;

    return q1[f1++];
}

void display() {
    int i;

    if (f1 > r1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack: ");

    for (i = f1; i <= r1; i++)
        printf("%d ", q1[i]);

    printf("\n");
}

int main() {
    int choice, x;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (r1 == MAX - 1) {
                    printf("Stack Overflow\n");
                    break;
                }

                printf("Enter element: ");
                scanf("%d", &x);
                push(x);
                display();
                break;

            case 2:
                x = pop();

                if (x == -1)
                    printf("Stack is Empty\n");
                else
                    printf("Popped: %d\n", x);

                display();
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