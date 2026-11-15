// 3. Write a C program that evaluates a postfix expression by using a stack to store
// operands and applying operators in the correct order to obtain the final numerical
// result.
// Eg.: Input: 23*54*+9-
// Evaluation → ((2*3)+(5*4))-9 = 17


#include <stdio.h>
#include <ctype.h>

int stack[100], top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluate(char exp[]) {
    int i, a, b;

    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i]))
            push(exp[i] - '0');

        else {
            b = pop();
            a = pop();

            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    return pop();
}

int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    printf("Result = %d\n", evaluate(exp));

    return 0;
}