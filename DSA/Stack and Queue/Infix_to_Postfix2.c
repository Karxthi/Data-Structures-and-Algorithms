#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *stk;
int top = -1;
int MAX;

bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == MAX - 1;
}

char peek()
{
    return stk[top];
}

char pop()
{
    if (isEmpty())
        return -1;

    char ch = stk[top];
    top--;
    return (ch);
}

void push(char oper)
{
    if (isFull())
        printf("Stack Full!!!!");

    else
    {
        top++;
        stk[top] = oper;
    }
}

int checkIfOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

void convertInfixToPostfix(char *expression)
{
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i)
    {
        if (checkIfOperand(expression[i]))
            expression[++j] = expression[i];

        else if (expression[i] == '(')
            push(expression[i]);

        else if (expression[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
                expression[++j] = pop();
            if (!isEmpty() && peek() != '(')
                return;
            else
                pop();
        }
        else
        {
            while (!isEmpty() && precedence(expression[i]) <= precedence(peek()))
                expression[++j] = pop();
            push(expression[i]);
        }
    }

    while (!isEmpty())
        expression[++j] = pop();

    expression[++j] = '\0';
    printf("%s\n", expression);
}

int main()
{
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &MAX);

    stk = (char *)malloc(MAX * sizeof(char));
    if (stk == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    getchar(); // Consume newline character left in the input buffer

    char expression[MAX];
    printf("Enter the infix expression: ");
    fgets(expression, MAX, stdin);

    convertInfixToPostfix(expression);

    free(stk);
    return 0;
}
