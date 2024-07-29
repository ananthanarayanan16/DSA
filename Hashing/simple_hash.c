// IMPLEMENTATION OF SIMPLE HASHING

#include<stdio.h>
#include<stdlib.h>
#define size 10

int hash_table[size];

//  INSERT FUNCTION

int insert()
{
    int num,hash_key;
    printf("\nEnter a number to insert into the hash table : ");
    scanf("%d",&num);
    hash_key = num % size;
    if(hash_table[hash_key] == 0)
    {
        hash_table[hash_key] = num;
    }
    return 0;
}


// DISPLAY FUNCTION

int display()
{
    for(int i = 0; i < size; i++)
    {
        printf("\nIndex - %d  element : %d",i,hash_table[i]);
    }
}


//  SEARCH FUNCTION

int search()
{
    int num,hash_key;
    printf("\nEnter the  number for search : ");
    scanf("%d",&num);
    hash_key = num % size;
    if(hash_table[hash_key] == num)
    {
        printf("\nThe given number %d found at the index : %d\n",num,hash_key);
    }
    else
    {
        printf("\nThe given number %d not found in the hash table.\n",num);
    }
    return 0;
}


// DELETE FUNCTION

int delete()
{
    int num,hash_key;
    printf("\nEnter the number for delete : ");
    scanf("%d",&num);
    hash_key = num % size;
    printf("\nThe given number %d is deleted in the hash table.",hash_table[hash_key]);
    hash_table[hash_key] = 0;
}


// MAIN FUNCTION

int main()
{
    int option;
    while(1)
    {
        printf("\n**********MAIN MENU**********\n");
        printf("1.Insert\n");
        printf("2.Search\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("\nEnter your option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                insert();
            break;
            case 2:
                search();
            break;
            case 3:
                delete();
            break;
            case 4:
                display();
            break;
            case 5:
                exit(0);
            break;
            default:
                printf("\nWrong option.\n");
            break;
        }
    }
    return 0;
}