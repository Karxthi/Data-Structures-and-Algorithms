#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char *Stack;
int top = -1;
int MAX;

bool isEmpty()  // Underflow
{  if(top == -1){
    return true;
    }
    else{
        return false;
    }
}  

bool isFull()  // Overflow
{  
    if(top ==MAX-1){
    return true;
    }
    else{
        return false;
    } 
}  
  

char peek()
{
    return Stack[top];
}

char pop()
{
    if (isEmpty())
        return -1;

    char ch = Stack[top];
    top--;
    return (ch);
}

void push(char E)
{
    if (isFull())
        printf("\n Oveflow Stack is Full");

    else
    {
        top++;
        Stack[top] = E;
    }
}

int IsOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Priority(char ch)
{
    
    switch(ch){
        case '-':
        case '+':
            return 1; // Lower Priority
        case '*':
        case '/':
            return 2; // Higher Priority
        default:
            return -1;
    }
}

void toPostfix(char *infixstring)
{
  int i,j;
    for (i = 0,j=-1; infixstring[i]; ++i)
    {
        if (IsOperand(infixstring[i]))
            infixstring[++j] = infixstring[i]; // appending the same character to output if its an operand

        else if (infixstring[i] == '(')
            push(infixstring[i]);    // Priority pushnig

        else if (infixstring[i] == ')') // till '('
        {
            while ((isEmpty()==false) && peek() != '(')
                infixstring[++j] = pop();
            if ((isEmpty()==false) && peek() != '(')
                return;
            else
                pop();
        }
        else
        {
            while ((isEmpty()==false) && Priority(infixstring[i]) <= Priority(peek()))
                infixstring[++j] = pop();
            push(infixstring[i]);
        }
    }

    while (!isEmpty())
        infixstring[++j] = pop();

    infixstring[++j] = '\0';
    printf("%s\n", infixstring);
}

int main()
{
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &MAX);

    Stack = (char *)malloc(MAX * sizeof(char));

    getchar(); // Consume newline character left in the input buffer

    char infixstring[MAX];
    printf("Enter the infix infixstring: ");
    fgets(infixstring, MAX, stdin);

    toPostfix(infixstring);

    free(Stack);
    return 0;
}
