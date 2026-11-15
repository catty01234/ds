// 8. Write a C program to implement a Stack using two Queues such that the Push
// operation runs in constant time (O(1)) and the Pop operation runs in linear time
// (O(n)).
// Display the contents of the stack after each operation.

#include <stdio.h>
#define MAX 100

int q1[MAX], q2[MAX];
int f1 = 0, r1 = -1;
int f2 = 0, r2 = -1;

void push(int x) {
    if (r1 == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    q1[++r1] = x;
}

int pop() {
    int x;

    if (r1 == -1)
        return -1;

    while (f1 < r1)
        q2[++r2] = q1[f1++];

    x = q1[f1];

    f1 = 0;
    r1 = -1;

    while (f2 <= r2)
        q1[++r1] = q2[f2++];

    f2 = 0;
    r2 = -1;

    return x;
}

void display() {
    int i;

    if (r1 == -1) {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack: ");

    for (i = r1; i >= f1; i--)
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