// CIRCULAR DOUBLE LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node node ;

node *head = NULL;

// FUNCTIONS

int count()
{
    node *temp;
    int count = 0;
    temp = head;
    while(temp != NULL)
    {
        count++;
        if(temp->next == head)
        {
            goto out;
        }
        else
        {
            temp = temp->next;
        }
    }
    out:
    return count;
}

// CREATE A LIST.

void create_list()
{
    node *new_node,*temp;
    int num;
    printf("\nEnter -1 to end.");
    while(num != -1)
    {
        printf("\nEnter the number : ");
        scanf("%d",&num);
        if(num != -1)
        {
            new_node = (node*)malloc(sizeof(node));
            new_node->data = num;
            if(head == NULL)
            {
                head = new_node;
                new_node->next = NULL;
                new_node->prev = NULL;
            }
            else
            {
                if(head->next == NULL)
                {
                    head->next = new_node;
                    head->prev = new_node;
                    new_node->prev = head;
                    new_node->next = head;
                }
                else
                {
                    temp = head;
                    while(temp->next != head)
                    {
                        temp = temp->next;
                    }
                    new_node->next = temp->next;
                    new_node->prev = temp;
                    temp->next = new_node;
                    temp = new_node->next;
                    temp->prev = new_node;
                }
            }
        }
    }
}


// DISPLAY THE LIST

void display_list()
{
    node *temp;
    if(head == NULL)
    {
        printf("\nList is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            if(temp->next != head)
            {
                printf("\t%d",temp->data);
                temp = temp->next;
            }
            else
            {
                printf("\t%d",temp->data);
                goto out;
            }
        }
        out:
        printf("\nAvailabel nodes are : %d",count());
    }
    // ERROR : segmentation fault (core dumped) for put the below statements outside of the else part
    // out:
    // printf("\nAvailabel nodes are : %d",count());
}


// INSERT SINGLE NODE AT THE BEGINNING

void insert_begin_single()
{
    node *new_node,*temp;
    new_node = (node*)malloc(sizeof(node));
    printf("\nEnter the number : ");
    scanf("%d",&(new_node->data));
    if(head == NULL)
    {
        printf("\nList not created.");
    }
    else if(head->next == NULL && head->prev == NULL)
    {
        new_node->next = head;
        new_node->prev = head;
        head->prev = new_node;
        head->next = new_node;
        head = new_node;
    }
    else
    {
        temp = head->prev;
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev = new_node;
        temp->next = new_node;
        head = new_node;
    }
}


// INSERT MULTIPLE ELEMENT AT THE BEGINNING OF THE LIST

void insert_begin()
{
    node *new_node,*temp;
    int n;
    printf("\nEnter number of element to be insert : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        new_node = (node*)malloc(sizeof(node));
        printf("\nEnter the number : ");
        scanf("%d",&(new_node->data));
        if(head == NULL)
        {
            printf("\nThe list is empty.");
        }
        else if(head->next == NULL)
        {
            new_node->next = head;
            new_node->prev = head;
            head->prev = new_node;
            head->next = new_node;
            head = new_node;
        }
        else
        {
            temp = head->prev;
            new_node->next = head;
            new_node->prev = head->prev;
            head->prev = new_node;
            temp->next = new_node;
            head = new_node;
        }
    }
}


// INSERT SINGLE ELEMENT AT THE END OF THE LIST

void insert_end_single()
{
    node *new_node,*temp;
    printf("\nEnter the number : ");
    scanf("%d",&(new_node->data));
    temp = head->prev;
    new_node->prev = temp;
    temp->next = new_node;
    new_node->next = head;
    head->prev = new_node;
}


// INSERT MULTIPLE ELEMENT AT THE END OF THE LIST

void insert_end()
{
    node *new_node,*temp;
    int n;
    printf("\nEnter number of element to be insert : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        new_node = (node*)malloc(sizeof(node));
        printf("\nEnter the number : ");
        scanf("%d",&(new_node->data));
        if(head == NULL)
        {
            printf("\nThe list is empty.");
        }
        else if(head->next == NULL)
        {
            new_node->next = head;
            new_node->prev = head;
            head->prev = new_node;
            head->next = new_node;
        }
        else
        {
            temp = head->prev;
            new_node->prev = temp;
            new_node->next = temp->next;
            temp->next = new_node;
            head->prev = new_node;
        }
    }
}


// INSERT SINGLE NODE AFTER THE POSITION

void insert_after_single()
{
    node *new_node,*temp_1,*temp_2;
    int pos;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    if(pos == count())
    {
        insert_end_single();
    }
    else
    {
        temp_1 = head;
        new_node = (node*)malloc(sizeof(node));
        printf("\nEnter the number : ");
        scanf("%d",&(new_node->data));
        for(int i=1;i<pos;i++)
        {
            temp_1 = temp_1->next;
        }
        new_node->prev = temp_1;
        new_node->next = temp_1->next;
        temp_2 = temp_1->next;
        temp_1->next = new_node;
        temp_2->prev = new_node;
    }
}

// INSERT MULTIPLE NODES AFTER THE POSITION

void insert_after()
{
    node *new_node,*temp_1,*temp_2;
    int pos,n;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    if(pos == count())
    {
        insert_end();
    }
    else
    {
        printf("\nEnter number of nodes to be insert : ");
        scanf("%d",&n);
        temp_1 = head;
        for(int i=1;i<pos;i++)
        {
            temp_1 = temp_1->next;
        }
        for(int i=1;i<=n;i++)
        {
            new_node = (node*)malloc(sizeof(node));
            printf("\nEnter the number : ");
            scanf("%d",&(new_node->data));
            new_node->next = temp_1->next;
            new_node->prev = temp_1;
            temp_2 = temp_1->next;
            temp_1->next = new_node;
            temp_2->prev = new_node;
        }
    }
}


// INSERT SINGLE NODES BEFORE THE POSITION

void insert_before_single()
{
    node *new_node,*temp_1,*temp_2;
    int pos;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    if(pos == 1)
    {
        insert_begin_single();
    }
    else
    {
        temp_1 = head;
        for(int i=1;i<pos;i++)
        {
            temp_1 = temp_1->next;
        }
        new_node = (node*)malloc(sizeof(node));
        printf("\nEnter the number : ");
        scanf("%d",&(new_node->data));
        temp_2 = temp_1->prev;
        new_node->next = temp_1;
        new_node->prev = temp_1->prev;
        temp_1->prev = new_node;
        temp_2->next = new_node;
    }
}


// INSERT MULTIPLE NODES BEFORE THE POSITION

void insert_before()
{
    node *new_node,*temp_1,*temp_2;
    int pos,n;
    printf("\nEnter the position to be insert : ");
    scanf("%d",&pos);
    if(pos == 1)
    {
        insert_begin();
    }
    else
    {
        temp_1 = head;
        for(int i=1;i<pos;i++)
        {
            temp_1 = temp_1->next;
        }
        printf("\nEnter number of nodes to be insert : ");
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            new_node = (node*)malloc(sizeof(node));
            printf("\nEnter the number : ");
            scanf("%d",&(new_node->data));
            temp_2 = temp_1->prev;
            new_node->next = temp_1;
            new_node->prev = temp_2;
            temp_1->prev = new_node;
            temp_2->next = new_node;
            temp_1 = new_node;
        }
    }
}


// DELETE SINGEL NODE FROM THE BEGIN OF THE LIST

void delete_begin_single()
{
    node *temp,*tail;
    temp = head->next;
    if(temp == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        temp->prev = head->prev;
        tail = head->prev;
        tail->next = temp;
        free(head);
        head = temp;
    }
}


// DELETE MULTIPLE NODES FROM THE BEGIN OF THE LIST

void delete_begin()
{
    node* temp,*tail;
    int n;
    printf("\nEnter number of nodes delete from the beginning : ");
    scanf("%d",&n);
    if(n > count())
    {
        printf("\nThe given number is greater than the list.");
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            temp = head->next;
            temp->prev = head->prev;
            if(temp == head || (head->next == NULL && head->prev == NULL))
            {
                free(head);
                head = NULL;
            }
            else
            {
                tail = head->prev;
                tail->next = temp;
                free(head);
                head = temp;    
            }
        }
    }
}

// DELETE SINGLE NODE FROM THE LAST

void delete_last_single()
{
    node *temp,*tail;
    temp = head->prev;
    if(temp == head)
    {
        free(head);
        head = NULL; 
    }
    else
    {
        tail = temp->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}



// DELETE MULTIPLE NODE FROM THE LAST 

void delete_last()
{
    node *temp,*tail;
    int n;
    printf("\nEnter number of nodes to be delete from the last : ");
    scanf("%d",&n);
    if(n > count())
    {
        printf("\nThe given number is greater than the list.");
    }
    else
    {
        for(int i = 1;i <= n; i++)
        {
            
            temp = head->prev;
            if(temp == head)
            {
                free(head);
                head = NULL;
            }
            else
            {
                tail = temp->prev;
                tail->next = head;
                head->prev = tail;
                free(temp);   
            }                
        }
    }
}


// DELETE MULTIPLE NODES FROM THE SPECIFIED POSITION

void delete_position()
{
    node *temp_1,*temp_2,*temp_3;
    int pos,n;
    printf("\nEnter the position to be delete : ");
    scanf("%d",&pos);
    if(pos == 1)
    {
        delete_begin();
    }
    else if(pos == count())
    {
        delete_last();
    }
    else
    {
        temp_1 = head;
        for(int i = 1; i < pos; i++)
        {
            temp_1 = temp_1->next;
        }
        printf("\nEnter number of nodes to be delete : ");
        scanf("%d",&n);
        if(n > count())
        {
            printf("\nThe given number is greater than the list.");
        }    
        else
        {
            for(int i = 1; i <= n; i++)
            {
            // if(n > count())
            // {
                // printf("\nThe given nummber is greater than the list.");
            // }
            // else
            // {
                if(temp_1->next == head)
                {
                    head->next = NULL;
                    head->prev = NULL;
                }
                else
                {
                    temp_2 = temp_1->prev;
                    temp_3 = temp_1->next;
                    temp_2->next = temp_3;
                    temp_3->prev = temp_2;
                    free(temp_1);
                    temp_1 = temp_3;
                }
            // }
            }
        }
    }
}



// MAIN FUNCTION

void main()
{
    int option;
    while(1)
    {
        printf("\n***************DOUBLE LINKED LIST***************\n");
        printf("1.Create a circular doubel linked list.\n");
        printf("2.Display the list.\n");
        printf("3.Insert at the beginning\n");
        printf("4.Insert at the end\n");
        printf("5.Insert after the position\n");
        printf("6.Insert before the position\n");
        printf("7.Delete a node from the first position.\n");
        printf("8.Delete a node from the last position.\n");
        printf("9.Delete a node from the specified position.\n");
        printf("10.Exit.\n");
        printf("Enter the option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                create_list();
            break;
            case 2:
                display_list();
            break;
            case 3:
                insert_begin();
            break;
            case 4:
                insert_end();
            break;
            case 5:
                insert_after();
            break;
            case 6:
                insert_before();
            break;
            case 7:
                delete_begin();
            break;
            case 8:
                delete_last();
            break;
            case 9:
                delete_position();
            break;
            case 10:
                exit(0);
            break;
            default:
                printf("\nWrong option.\n");
            break;
        }
    }
}