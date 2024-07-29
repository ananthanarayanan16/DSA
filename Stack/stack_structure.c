// IMPLIMENTATION STACK USING STRUCTURE 

#include<stdio.h>
#include<stdlib.h>
#define max 5
int top = 0;

struct node
{
    int data;
    struct node *next;
};

typedef struct node stack;
stack *head = NULL;

// PUSH FUNCTION

void push()
{
    stack *new_node,*temp;
    if(top < max)
    {
        new_node = (stack*)malloc(sizeof(stack));
        printf("\nEnter number to be push in the stack : ");
        scanf("%d",&(new_node->data));
        if(head == NULL)
        {
            head = new_node;
            head->next = NULL;
            top++;
        } 
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            top++;
        }
    }
    else
    {
        printf("\nSTACK OVERFLOW");
    }
}


// DISPLAY FUNCTION

void display()
{
    int n = top;
    stack *temp;
    // temp = head;
    if(head == NULL)
    {
        printf("\nSTACK IS EMPTY");
    }
    else
    {
        for(int i = 0; i < top; i++)
        {
            temp = head;
            for(int j = 0;j < n-1; j++)
            {
                temp = temp->next;
            }
            printf("\n%d",temp->data);
            n--;
        }
    }
}


// POP FUNCTION 

void pop()
{
    stack *temp_1,*temp_2;
    if(top == 0)
    {
        printf("\nSTACK UNDERFLOW");
    }
    else
    {
        if(top == 1)
        {
            printf("\nThe deleted element in the stack is : %d",head->data);
            free(head);
            head = NULL;
            top--;
        }
        else
        {   
            temp_1 = head;
            for(int i = 0; i < top-2; i++)  // FIND THE PERVIOUS ELEMENT OF THE LAST ELEMENT SO PUT " top-2 ".
            {
                temp_1 = temp_1->next;
            }
            temp_2 = temp_1->next;
            printf("\nThe deleted element in the stack is : %d",temp_2->data);
            free(temp_2);
            temp_1->next = NULL;
            top--;
        }
    }
}


// PEEK FUNCTION

void peek()
{
    stack *temp;
    if(top == 0)
    {
        printf("\nSTACK IS EMPTY");
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        printf("\nThe peek element in the stack is : %d",temp->data);
    }
}


// MAIN FUNCTION

int main()
{
    int choice;
    while(1)
    {
        printf("\n***************MAIN MENU***************\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice : ");
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
                printf("\nWrong choice");
            break;
        }
    }
    return 0;
}

