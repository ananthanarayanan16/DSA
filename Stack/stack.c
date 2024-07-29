// STACK IMPLEMENTATION

#include<stdio.h>
#include<stdlib.h>
#define max 5

int stack[max];
int top = 0;

// PUSH THE DATA IN THE STACK

void push()
{
    if(top == max)
    {
        printf("\nSTACK OVERFLOW.");
    }
    else
    {
        printf("\nEnter the number to be pushed in the stack : ");
        scanf("%d",&stack[top]);
        top++;
    }
}

// DISPLAY DATA IN THE STACK

void display()
{
    if(top == 0)
    {
        printf("\nThe stack is empty.");
    }
    else
    {
        for(int i=top-1;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

// DELETE THE DATA IN THE STACK

void pop()
{
    if(top == 0)
    {
        printf("\nSTACK UNDERFLOW.");
    }
    else
    {
        top--;
        printf("\nThe delete element in the stack is : %d",stack[top]);
        stack[top] = 0;
        printf("\nDeleted successfully.");
    }
}


// FIND THE PEEK ELEMENT IN THE STACK

void peek()
{
    if(top == 0)
    {
        printf("\nThe stack is empty.");
    }
    else
    {
        printf("\nThe peek element in the stack is : %d",stack[top-1]);
    }
}


// MAIN FUNCTION

int main()
{
    int choice;
    while(1)
    {
        printf("\n********Main Menu********\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
            break;
            case 2:
                pop();
            break;
            case 3:
                peek();
            break;
            case 4:
                display();
            break;
            case 5:
                exit(0);
            break;
            default:
                printf("\nWrong choice.");
            break;
        }
    }
    return 0;
}