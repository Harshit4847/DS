#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int peek() {
    if (top == -1) return -1;
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isBalanced(char* exp) {
    top = -1;
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push('(');
        } else if (exp[i] == ')') {
            if (isEmpty()) return 0;
            pop();
        }
    }
    return isEmpty();
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    top = -1;
    int j = 0;
    char ch;
    for (int i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int evalPostfix(char* postfix) {
    top = -1;
    int a, b;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            b = pop();
            a = pop();
            switch (ch) {
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
    int choice;
    char expr[100], postfix[100];

    while (1) {
        printf("\n--- Stack Applications ---\n");
        printf("1. Check Balanced Parentheses\n");
        printf("2. Infix to Postfix Conversion\n");
        printf("3. Evaluate Postfix Expression\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter expression: ");
                fgets(expr, sizeof(expr), stdin);
                expr[strcspn(expr, "\n")] = '\0';
                if (isBalanced(expr))
                    printf("Balanced \n");
                else
                    printf("Not Balanced \n");
                break;

            case 2:
                printf("Enter infix expression: ");
                fgets(expr, sizeof(expr), stdin);
                expr[strcspn(expr, "\n")] = '\0';
                infixToPostfix(expr, postfix);
                printf("Postfix: %s\n", postfix);
                break;

            case 3:
                printf("Enter postfix expression (single-digit operands): ");
                fgets(postfix, sizeof(postfix), stdin);
                postfix[strcspn(postfix, "\n")] = '\0';
                printf("Result = %d\n", evalPostfix(postfix));
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
