// IMPLEMENTATION OF DOUBLE HASHING AND USING THE LOAD FACTOR

#include<stdio.h>
#include<stdlib.h>
#define size 10

int hash_table[size],hash_key_1,hash_key_2,index,value,i;


// FIND  A PRIME NUMBER FROM TABLE SIZE "SIZE" 

int prime()
{
    int count;
    for(int i = size; i >= 2; i--)
    {
        count = 0;
        for(int j = 2; j <= i; j++)
        {
            if(i % j == 0)
            {
                count++;
            }
        }
        if(count == 1)
        {
            return i;
        }
    }
}


// HASH FUNCTION

int hash(int value)
{
    hash_key_1 = value % size;
    // printf("\nPrime number is : %d",prime());
    hash_key_2 = prime() - (value % prime());
    for(i = 0; i < size; i++)
    {
        index = (hash_key_1 + (i * hash_key_2)) % size;
        if(hash_table[index] == 0)
        {
            hash_table[index] = value;
            return i;
        }
    }
    return i;
}


// INSERT FUNCTION

int insert()
{
    printf("\nEnter the value to be insert : ");
    scanf("%d",&value);
    if(hash(value) == size)
    {
        printf("\nHash table is full.");
        return 0;
    }
}


// DISPLAY FUCNTION

int display()
{
    printf("\nThe element in the hash table are :\n");
    for(int i = 0; i < size; i++)
    {
        printf("Index - [%d] : %d\n",i,hash_table[i]);
    }
    return 0;
}


// SEARCH FUNCTION

int search()
{
    printf("\nEnter a value to be search : ");
    scanf("%d",&value);
    hash_key_1 = value % size;
    hash_key_2 = prime() - (value % prime());
    for(i = 0; i < size; i++)
    {
        index = (hash_key_1 + (i * hash_key_2)) % size;
        if(hash_table[index] == value)
        {
            printf("\nThe given value %d is found at the index : %d",value,index);
            return 0;
        }
    }
    if(i == size)
    {
        printf("\nThe given value %d is not found in the hash table.",value);
        return 0;
    }
}


//  DELETE FUNCTION

int delete()
{
    printf("\nEnter the value to be delete : ");
    scanf("%d",&value);
    hash_key_1 = value % size;
    hash_key_2 = prime() - (value % prime());
    for(i = 0; i < size; i++)
    {
        index = (hash_key_1 + (i * hash_key_2)) % size;
        if(hash_table[index] == value)
        {
            printf("\nThe given value %d is delete in the hash table.",hash_table[index]);
            hash_table[index] = 0;
            return 0;
        }
    }
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
        printf("\nEnter yout option : ");
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