// LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insertbegin(struct node *);
struct node *insertend(struct node *);
struct node *after_position(struct node *);
struct node *before_position(struct node *);

int main()
{
    int option;

    do
    {
        printf("\n********Main Menu********\n");
        printf("1.Creat a list\n");
        printf("2.Display the list\n");
        printf("3.Insert at the beginning\n");
        printf("4.Insert at the end\n");
        printf("5.Insert after the position\n");
        printf("6.Insert before the position\n");
        printf("7.Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                start = create(start);
                printf("\nLinked list created.");
            break;
            case 2:
                start = display(start);
            break;
            case 3:
                start = insertbegin(start);
                printf("\nValue inserted at the beginning of the linked list.");
            break;
            case 4:
                start = insertend(start);
                printf("\nValue inserted at the end of the linked list.");
            break;
            case 5:
                start = after_position(start);
                printf("\nValue insert after the Position.");
            break;
            case 6:
                start = before_position(start);
                printf("\nValue insert before the position.");
            break;
            default:
                printf("\nWrong Option");
            break;
        }
    }
    while(option != 7);
    return 0;
}

//CREATE FUNCTIONS

struct node *create(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to end.");
    printf("\nEnter the data : ");
    scanf("%d",&num);
    while(num != -1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
        {
            printf("\nMemory cannot allocated");
            return 0;
        }    
        new_node -> data = num;
        if(start == NULL)
        {
            start = new_node;
            new_node->next = NULL;
        }
        else
        {
            ptr=start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf("\nEnter a data : ");
        scanf("%d",&num);
    }
    return start;
}


// DISPLAY FUNCTION

struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    return start;
}


/*
// INSERT AT THE BEGINNING SINGLE ELEMENT

struct node *insertbegin(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("Enter the data : ");
    scanf("%d",&num);
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("\nMemory cannot be allocated.");
        return start;
    }
    ptr=start;
    new_node->data = num;
    new_node->next = ptr;
    start = new_node;
}
*/

// INSERT MULTIPLE ELEMENT AT THE BEGIN

struct node *insertbegin(struct node *start)
{
    struct node *new_node,*temp;
    int n;
    // temp = start;
    printf("\nEnter number element to be insert : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        if(new_node == NULL)
        {
            printf("\nMemory cannot be allocated.");
            return 0;
        }
        printf("\nEnter the number : ");
        scanf("%d",&(new_node->data));
        new_node->next = start;
        // temp = new_node;
        start = new_node;
    }
    return start;
}
/*

// INSERT SINGLE AT THE END

struct node *insertend(struct node *start)
{
    struct node *new_node,*ptr;
    ptr = start;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the number : ");
    scanf("%d",&(new_node->data));
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;
    return start;
}
*/
// MULTIPLE ELEMENT INSERT AT THE END

struct node *insertend(struct node *start)
{
    struct node *new_node,*ptr;
    int n,num;
    printf("\nEnter no of element to be insert at the END : ");
    scanf("%d",&n);
    ptr = start;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    for(int i=1;i<=n;i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the number : ");
        scanf("%d",&(new_node->data));
        ptr->next = new_node;
        new_node->next = NULL;
        ptr = new_node;
    }
    return start;
}
/*

// INSERT AT THE POSITIN 

struct node *after_position(struct node *start)
{
    struct node *new_node,*ptr;
    int n;
    ptr = start;
    printf("\nEnter the position : ");
    scanf("%d",&n);
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the number : ");
    scanf("%d",&(new_node->data));
    for(int i=1;i<n;i++)
    {
        if(ptr->next == NULL)
        {
            printf("\nThe list is end.The entered number is greater then the list.");
            return start;
        }
        if(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    return start;
}
*/

//INSERT AFTER THE POSITION MULTIPLE ELEMENT

struct node *after_position(struct node *start)
{
    struct node *new_node,*ptr;
    int n,m;
    ptr = start;
    printf("\nEnter the position : ");
    scanf("%d",&n);
    printf("\nEnter no of element : ");
    scanf("%d",&m);
    for(int i=1;i<n;i++)
    {
        if(ptr->next == NULL)
        {
            printf("\nThe list is end.The entered number is greater then the list.");
            return start;
        }
        if(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
    }
    for(int i=1;i<=m;i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the number : ");
        scanf("%d",&(new_node->data));
        new_node->next = ptr->next;
        ptr->next = new_node;
        ptr = new_node;
    }
    return start;
}
/*

//INSERT SINGLE ELEMENT BEFOR THE POSITION

struct node *before_position(struct node *start)
{
    struct node *new_node,*ptr;
    int n;
    ptr = start;
    printf("\nEnter the position : ");
    scanf("%d",&n);
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the number : ");
    scanf("%d",&(new_node->data));
    for(int i=1;i<n-1;i++)
    {
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    return start;
}
*/

// INSERT MULTIPLE ELEMENT BEFORE THE POSITION

struct node *before_position(struct node *start)
{
    struct node *new_node,*ptr;
    int n,m;
    ptr = start;
    printf("\nEnter the position : ");
    scanf("%d",&n);
    printf("\nEnter the number of element : ");
    scanf("%d",&m);
    for(int i=1;i<n-1;i++)
    {
        ptr = ptr->next;
    }
    for(int i=1;i<=m;i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the number : ");
        scanf("%d",&(new_node->data));
        new_node->next = ptr->next;
        ptr->next= new_node;
        ptr = new_node;
    }
    return start;
}