//  IMPLEMENTATION OF CHAINED HASHING

#include <stdio.h>
#include <stdlib.h>
#define size 10

//  DECLAREING VARIABLE IN GOLBAL

long int *hash_table;
int value, index;

//  CREATE NODE

typedef struct node
{
    int data;
    struct node *next;
} node;

// HASH FUNCTION

int hash_function(int value)
{
    return value % size;
}

//  INSERT FUNCTION

int insert()
{
    node *new_node, *ptr;
    new_node = (node *)malloc(sizeof(node));
    printf("Enter a value to insert into hash table : ");
    scanf("%d", &value);
    new_node->data = value;
    index = hash_function(value);
    if (hash_table[index] == NULL)
    {
        new_node->next = NULL;
        hash_table[index] = new_node;
    }
    else
    {
        ptr = hash_table[index];
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = NULL;
    }
}

// DISPLAY FUNCTION

int display()
{
    node *ptr;
    printf("\nElement in the hash table : \n");
    for (int i = 0; i < size; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\nIndex - [%d]\tvalue : %d", i, hash_table[i]);
        }
        else
        {
            printf("\nIndex - [%d]\tvalue : ", i);
            ptr = hash_table[i];
            while (ptr != NULL)
            {
                printf("%d\t", ptr->data);
                ptr = ptr->next;
            }
        }
    }
    return 0;
}

// SEARCH FUNCTION

int search()
{
    int pos = 1, count = 0;
    node *ptr;
    printf("\nEnter search element : ");
    scanf("%d", &value);
    index = hash_function(value);
    if (hash_table[index] != NULL)
    {
        ptr = hash_table[index];
        while (ptr != NULL)
        {
            if (ptr->data == value)
            {
                printf("\nThe element is found at index %d and position %d.", index, pos);
                count++;
            }
            pos++;
            ptr = ptr->next;
        }
        if (count == 0)
        {
            printf("\nThe element %d is not found in the hash table.", value);
        }
    }
    else
    {
        printf("\nThe element %d is not found in the hash table.", value);
    }
}

//  DELETE FUNCTION

int delete()
{
    int pos = 1, count = 0;
    node *ptr, *temp;
    printf("\nEnter the element to be delete : ");
    scanf("%d", &value);
    index = hash_function(value);
    if (hash_table[index] != NULL)
    {
        ptr = hash_table[index];
        while (ptr != NULL)
        {
            if (ptr->data == value)
            {
                printf("\nThe delete element %d is found in the index %d and positoin %d", value, index, pos);
                count++;
                break;
            }
            pos++;
            ptr = ptr->next;
        }
        if (count > 0)
        {
            if (pos == 1)
            {
                hash_table[index] = ptr->next;
                free(ptr);
            }
            else
            {
                ptr = hash_table[index];
                for (int i = 1; i < pos - 1; i++)
                {
                    ptr = ptr->next;
                }
                temp = ptr->next;
                ptr->next = temp->next;
                free(temp);
            }
        }
        else
        {
            printf("\nThe element %d is not founded in the hash table.",value);
        }
    }
    else
    {
        printf("\nThe element %d is not founded in the hash table.", value);
    }
}

//  MAIN FUNCTION

int main()
{
    int choice;
    hash_table = (long int *)calloc(size, sizeof(long int));

    while (1)
    {
        printf("\n**********MAIN MENU***********\n");
        printf("1.Insert\n");
        printf("2.Search\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("\nEnter yout choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            delete ();
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
