//  IMPLEMENTATION OF QUADRATIC HASHING

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 10

int hash_table[size],count = 0;

//  INSERT FUCNTION

int insert()
{
    int i, hash_key, num, index;
    printf("\nEnter a number to be insert : ");
    scanf("%d", &num);
    hash_key = num % size;
    for (i = 0; i < size; i++)
    {
        index = (hash_key + (i * i)) % size;
        if (hash_table[index] == 0)
        {
            hash_table[index] = num;
            count++;
            break;
        }
    }
    if(count == 9)
    {
        printf("\nThe hash table is full");
    }
    return 0;
}

// DISPLAY FUNCTION

int display()
{
    printf("\nElement in the hash table are : \n");
    for (int i = 0; i < size; i++)
    {
        printf("\nIndex - [%d]  element : %d", i, hash_table[i]);
    }
    return 0;
}

// SEARCH FUNCTION

int search()
{
    int i, hash_key, num, index;
    printf("\nEnter the number to be search in the hash table : ");
    scanf("%d",&num);
    hash_key = num % size;
    for(i = 0; i < size; i++)
    {
        index = (hash_key + (i * i)) % size;
        if(hash_table[index] ==  num)
        {
            printf("\nThe given number %d found in the index : %d",num,index);
            break;
        }
    }
    if(i == size)
    {
        printf("\nThe give number %d not found in the hash table.",num);
    }
    return 0;
}


//  DELETE FUNCTION

int delete()
{
    int i,hash_key,num,index;
    printf("\nEnter the number to be delete : ");
    scanf("%d",&num);
    hash_key = num % size;
    for(i = 0; i < size; i++)
    {
        index = (hash_key + (i * i)) % size;
        if(hash_table[index] == num)
        {
            printf("\nThe given number %d is delete in the hash table",num);
            hash_table[index] = 0;
            return 0;
        }
    }
}



// MAIN FUCNTION

int main()
{
    int choice;
    while (1)
    {
        printf("\n**********MAIN MENU**********\n");
        printf("1.Insert\n");
        printf("2.Search\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Exit\n");
        printf("\nEnter your choice : ");
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
            delete();
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
    return 0;
}
