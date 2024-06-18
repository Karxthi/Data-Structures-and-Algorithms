#include "stdio.h"
#include "ctype.h"
#include "math.h"
#include <stdbool.h>

int maxsize = 30;
int stack[30];
int top = -1;

bool isFull(){
    return (top == (maxsize-1));
}

bool isEmpty(){
    return (top == -1);
}

void push(char x){
    if (isFull()){
        printf("Stack Full");
    }
    else{
        stack[++top] = x;
    }
}

int pop()
{
    if(isEmpty())
        return -1;
    else
        return stack[top--];
}

int main()
{
    char exp[30], *e;
    int n1, n2, n3, num;

    printf("\nEnter the expression : ");
    scanf("%s", exp);
    e = exp;

    while (*e != '\0')
    {
        if(isdigit(*e)){
            num = *e - '0';
            push(num);
        }
        else{
            n1 = pop();
            n2 = pop();

            switch (*e) {
                case '+':
                    n3 = n2 + n1;
                    break;
                case '-':
                    n3 = n2 - n1;
                    break;
                case '*':
                    n3 = n2 * n1;
                    break;
                case '/':
                    n3 = n2 / n1;
                    break;
                case '^':
                    n3 = pow(n2, n1);
                    break;
            }
            push(n3);
        }
        e++;
    }
    printf("\nThe evaluation of %s expression is %d", exp, pop());
}