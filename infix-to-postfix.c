// 2. Write a C program to evaluate a postfix expression and to convert an infix
// expression to postfix using stacks. Eg.: A+B*C —> ABC*+


#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[100];
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch))
            postfix[j++] = ch;

        else if (ch == '(')
            push(ch);

        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }

        else {
            while (top != -1 && stack[top] != '(' &&
                   (priority(stack[top]) > priority(ch) ||
                    (priority(stack[top]) == priority(ch) && ch != '^')))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main() {
    char infix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}