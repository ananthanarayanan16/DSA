// IMPLIMENTING LINEAR QUEUE

#include"stdio.h"
#include"stdlib.h"
int count = 0;

// CERATING NODE
struct node 
{
    int data;
    struct node *next;
};
typedef struct node node;

// DEFINE QUEUE  
struct queue
{
    node *front;
    node *rear;
};
typedef struct queue queue;
queue q;


// CREATING QUEUE 

void create_queue(queue *q)
{
    if(count == 0)
    {
        count++;
        q = (queue*)malloc(sizeof(queue));
        q->front = NULL;
        q->rear = NULL;
        printf("\nQueue is cerated");
    }
    else
    {
        printf("\nQUEUE ALREADY CREATED");
    }
}


// INSERT FUNCTION

void insert(queue *q)
{
    if(count > 0)
    {
        node *ptr;
        ptr = (node*)malloc(sizeof(node));
        printf("\nEnter the number : ");
        scanf("%d",&(ptr->data));
        if(q->front == NULL)
        {
            q->front = ptr;
            q->rear = ptr;
        }
        else
        {
            q->rear->next = ptr;
            q->rear = ptr;
        } 
    // q->rear = ptr;
    }
    else
    {
        printf("\nQUEUE NOT CREATED");
    }
}


// DISPLAY FUNCTION

void display(queue *q)
{
    node *temp;
    if(count > 0)
    {
        if(q->front == NULL)
        {
            printf("\nQUEUE IS EMPTY");
        }
        else
        {
            temp = q->front;
            while(temp != NULL)
            {
                printf("\t%d",temp->data);
                temp = temp->next;
            }
        }
    }
    else
    {
        printf("\nQUEUE NOT CERATED");
    }
}


// DELETE FUNCTION

void delete(queue *q)
{
    node *temp;
    if(count > 0)
    {
        if(q->front == NULL)
        {
            printf("\nQUEUE UNDERFLOW");
        }
        else
        {
            if(q->front->next == NULL)
            {
                printf("\nThe delete element in the queue is : %d",q->front->data);
                free(q->front);
                q->front = NULL;
            }
            else
            {
                temp = q->front;
                q->front = q->front->next;
                printf("\nThe delete element in the queue is : %d",temp->data);
                free(temp);
            }
        }
    }
}


// PEEK FUNCTION

void peek(queue *q)
{
    if(count > 0)
    {
        if(q->front == NULL)
        {
            printf("\nQUEUE IS EMPTY");
        }
        else
        {
            printf("\nThe peek element in the queue is : %d",q->front->data);
        }
    }
    else
    {
        printf("\nQUEUE NOT CREATED");
    }
}



// MAIN FUNCTION

int main()
{
    // queue q;
    int choice;
    while(1)
    {
        printf("\n**********MAIN MENU**********\n");
        printf("1.Create queue\n");
        printf("2.Insert\n");
        printf("3.Delelte\n");
        printf("4.Peek\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                create_queue(&q);
            break;
            case 2:
                insert(&q);
            break;
            case 3:
                delete(&q);
            break;
            case 4:
                peek(&q);
            break;
            case 5:
                display(&q);
            break;
            case 6:
                exit(0);
            break;
            default:
                printf("\nWrong choice\n");
            break;
        }
    }
    return 0;
}