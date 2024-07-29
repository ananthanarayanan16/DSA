// IMPLEMENTIOn OF CIRCULAR QUEUE IN ARRAY

#include "stdio.h"
#include "stdlib.h"
#define max 10

int queue[max];
int front = -1, rear = -1, count = 0;

// INSERT FUNCTION

void enqueue()
{
    if(count == max)
    {
        printf("\nQUEUE OVERFLOW");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        printf("\nEnter the number : ");
        scanf("%d",&queue[rear]);
        count++;
    }
    else if((front > 0 && front < max && rear == -1))
    {
        rear = 0;
        printf("\nEnter the number : ");
        scanf("%d",&queue[rear]);
        count++;
    }
    else
    {
        rear++;
        printf("\nEnter the number : ");
        scanf("%d",&queue[rear]);
        count++;
    }
}

//  DISPLAY FUNCTION

void display()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQUEUE IS EMPTY");
    }
    else if(rear < front)
    {
        // printf("\nfront = %d", front);
        // for (int i = front; i <= rear; i++)
        // {
            // printf("\t%d", queue[i]);
        // }
        for(int i = front; i < max; i++)
        {
            printf("\t%d",queue[i]);
        }
        for(int i = 0; i <= rear; i++)
        {
            printf("\t%d",queue[i]);
        }
    }
    else
    {
        // for(int i = front; i < max; i++)
        // {
            // printf("\t%d",queue[i]);
        // }
        // for(int i = 0; i <= rear; i++)
        // {
            // printf("\t%d",queue[i]);
        // }
        for (int i = front; i <= rear; i++)
        {
            printf("\t%d", queue[i]);
        }
    }
}

// DELETE FUNCTION

void dequeue()
{
    if (count == 0)  
    {
        printf("\nQUEUE UNDERFLOW");
    }
    else if(rear == max-1 && front == 0)
    {
        printf("\nThe delete element in the queue is : %d",queue[front]);
        queue[front] = 0;
        front++;
        count--;
        rear = -1;
    }
    else if(rear < front && front == max-1)
    {
        printf("\nThe delete element in the queue is : %d",queue[front]);
        queue[front] = 0;
        front = 0;
        count--;
    }
    else if(front == rear)
    {
        printf("\nThe delete element in the queue is : %d",queue[front]);
        queue[front] = 0;
        front = rear = -1;
        count--;
    }
    else
    {
        printf("\ntThe delete element in the queue is : %d",queue[front]);
        queue[front] = 0;
        front++;
        count--;
    }
}

// PEEK FUNCTION

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else
    {
        printf("\nThe Peek element in the queue is : %d", queue[front]);
    }
}

// MAIN FUNCTION

int main()
{
    int choice;
    while (1)
    {
        printf("\n**********QUEUE OPERATIONS**********\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
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
            printf("\nWrong choice\n");
            break;
        }
    }
}