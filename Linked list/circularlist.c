// IMPLEMENTATION OF CIRCULAR LINKED LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

// FUNCTIONS

//  COUTN NUMBER OF NODES IN THE LIST

int count()
{
    node *temp;
    int count = 1;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// CREATE CIRCULAR LINKED LIST

void create_circular_list()
{
    node *new_node, *temp;
    int num;
    printf("\nEnter -1 to end.");
    while (num != -1)
    {
        printf("\nEnter the number : ");
        scanf("%d", &num);
        if (num != -1)
        {
            new_node = (node *)malloc(sizeof(node));
            new_node->data = num;
            if (head == NULL)
            {
                new_node->next = NULL;
                head = new_node;
            }
            else
            {
                temp = head;
                while (temp->next != NULL && temp->next != head)
                {
                    temp = temp->next;
                }
                // if(temp->next == head)
                // {
                temp->next = new_node;
                new_node->next = head;
                // }
            }
        }
    }
}

// DISPLAY CIRCULAR LINKED LIST

void display()
{
    node *temp;
    // temp = head;
    if(head == NULL)
    {
        printf("\nThe list is empty.");
    }
    else
    {
        temp = head;
        while (temp != NULL) // && temp->next != head)
        {
            if (temp->next != head)
            {
                printf("\t%d", temp->data);
                temp = temp->next;
            }
            else
            {
                printf("\t%d", temp->data);
                goto out;
            }
        }
        out:
        printf("\nAvailable nodes are : %d", count());
    }
}

/*
// INSERT SINGLE NODE AT TEH BEGINNIGN OF THE LIST

void insert_begin_single()
{
    node *new_node,*temp;
    temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    new_node = (node*)malloc(sizeof(node));
    printf("\nEnter the number : ");
    scanf("%d",&(new_node->data));
    temp->next = new_node;
    new_node->next = head;
    head = new_node;
}
*/

// INSERT MULTIPLE NODE AT THE BEGINNING OF THE LIST

void insert_begin()
{
    node *new_node, *temp;
    int n;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    printf("\nEnter number of nodes to be insert : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        new_node = (node *)malloc(sizeof(node));
        printf("\nEnter the number : ");
        scanf("%d", &(new_node->data));
        temp->next = new_node;
        new_node->next = head;
        head = new_node;
    }
}

// INSERT SINGLE ELEMENT AT THE END OF THE LIST

void insert_end_single()
{
    node *new_node, *temp;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    new_node = (node *)malloc(sizeof(node));
    printf("\nEnter the number : ");
    scanf("%d", &(new_node->data));
    new_node->next = temp->next;
    temp->next = new_node;
}

// INSERT MULTIPLE ELEMENT AT THE END OF THE LIST

void insert_end()
{
    node *new_node, *temp;
    int n;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    printf("\nEnter number of element to be insert at the end : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        new_node = (node *)malloc(sizeof(node));
        printf("\nEnter the number : ");
        scanf("%d", &(new_node->data));
        new_node->next = temp->next;
        temp->next = new_node;
        temp = new_node;
    }
}

/*
// INSERT SINGLE NODE AFTER THE POSITION

void insert_after()
{
    node *new_node,*temp;
    int pos;
    temp = head;
    printf("\nEnter the position in the list : ");
    scanf("%d",&pos);
    if(pos == count())
    {
        insert_end_single();
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            temp = temp->next;
        }
        new_node = (node*)malloc(sizeof(node));
        printf("\nEnter the number : ");
        scanf("%d",&(new_node->data));
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
*/

// INSERT MULTIPLE NODES AFTER THE POSITION

void insert_after()
{
    node *new_node, *temp;
    int pos, n;
    temp = head;
    printf("\nEnter the position to be insert : ");
    scanf("%d", &pos);
    if (pos <= count())
    {
        if (pos == count())
        {
            insert_end();
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                temp = temp->next;
            }
            printf("\nEnter number of elemet to be insert : ");
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
            {
                new_node = (node *)malloc(sizeof(node));
                printf("\nEnter the number : ");
                scanf("%d", &(new_node->data));
                new_node->next = temp->next;
                temp->next = new_node;
                temp = new_node;
            }
        }
    }
    else
    {
        printf("\nGiven number is greater than the list.");
    }
}

// INSERT MULTIPLE NODES BEFORE THE POSITION

void insert_before()
{
    node *new_node, *temp;
    int pos, n;
    temp = head;
    printf("\nEnter the position : ");
    scanf("%d", &pos);
    if (pos > count())
    {
        printf("\nThe Given postion is greater than the list.");
    }
    else if (pos == 1)
    {
        insert_begin();
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        printf("\nEnter number of element to be insert : ");
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            new_node = (node *)malloc(sizeof(node));
            printf("\nEnter the number : ");
            scanf("%d", &(new_node->data));
            new_node->next = temp->next;
            temp->next = new_node;
            temp = new_node;
        }
    }
}

// DELETE MULTIPLE NODES FORM  THE BEGIN

void delete_begin()
{
    node *temp, *start;
     int n;
    temp = head;
    while(temp->next != head)
    {
    temp = temp->next;
    }
    printf("\nEnter number of element to be deleted in the begin : ");
    scanf("%d", &n);
    if (n > count())
    {
        printf("\nThe given number is greater then the list.");
    }
    else
    {
        for (int i=1;i<=n;i++)
        {
            if(head->next == NULL)
            {
                start = head->next;
                free(head);
                head = NULL;
            }
            else
            {
            start = head->next;
            free(head);
            head = start;
            if(temp == head)
            {
                temp->next = NULL;
            }
            else
            {
                temp->next = head;
            }
            }
        }
    }
}


// DELETE NODE FROM THE LAST OF THE LIST

void delete_last()
{
    node *temp,*last;
    int n,m;
    temp = head;
    printf("\nEnter number of nodes to be deleted from the last : ");
    scanf("%d",&n);
    if(n > count())
    {
        printf("\nThe given number is greater than the list.");
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(head->next == NULL)
            {
                free(head);
                head = NULL;
                goto out;
            }
            else
            {
                m = count();
                for(int j=1;j<m-1;j++)
                {
                    temp = temp->next;
                }
                // last = temp->next;
                if(temp->next == head)
                {
                    temp->next = NULL;
                    free(head);
                    head = NULL;
                }
                else
                {
                    last = temp->next;
                    temp->next = last->next;
                    free(last);
                }
                // free(last);
            }
            temp = head;
        }
        out:
    }
}


// DELETE NODE FROM THE SPECIFIED POSITION

void delete_position()
{
    node *temp,*position;
    int pos,n;
    printf("\nEnter the position from the list : ");
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
        temp = head;
        for(int i=1;i<pos-1;i++)
        {
            temp = temp->next;
        }
        position = temp->next;
        temp->next = position->next;
        free(position);
    }
}



// FUNCTION

void main()
{
    int option;
    while (1)
    {
        printf("\n***************CIRCUAR LINKED LIST****************\n");
        printf("1.Create Circular linked list\n");
        printf("2.Display the circular linked list\n");
        printf("3.Insert at the beginning\n");
        printf("4.Insert at the end of the list\n");
        printf("5.Insert after the position\n");
        printf("6.Insert before the position\n");
        printf("7.Delete a node from the first position\n");
        printf("8.Delete a node from the last position\n");
        printf("9.Delete a node form the specified position\n");
        printf("10.Exit\n");
        printf("\nEnter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            create_circular_list();
            break;
        case 2:
            display();
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
            printf("\nWrong option");
            break;
        }
    }
}
