// IMPLEMENTION OF LINEAR HASHING (HASH TABLE)

#include<stdio.h>
#include<stdlib.h>
#define size 10

int hash_table[size];  // IF VARIABLE DECLARE IN GLOBAL (OR) STATIC THE VALUE OF THE VARABLE IS DEFAULTLY INITIALIZE ZERO(0);


// INSERT FUCNTION

void insert()
{
    int i,value,hash_key,index;
    printf("\nEnter a value to insert into hash table : ");
    scanf("%d",&value);
    hash_key = value % size;
    for(i = 0; i < size; i++)
    {
        index = (hash_key + i) % size;
        printf("\nindex : %d",hash_key+i);
        if(hash_table[index] == 0)
        {
            hash_table[index] = value;
            break;
        }
    }
    if(i == size)
    {
        printf("\nTable is full element cannot be insert.");
    }
}


// DISPLAY FUNCTION

void display()
{
    printf("\nElement in the hash table are : \n");
    for(int i = 0; i < size; i++)
    {
        printf("\nAt Index %d \t Value %d",i,hash_table[i]);
    }
}


// SEARCH FUNCTION

void search()
{
    int i,value,hash_key,index;
    printf("\nEnter search element : ");
    scanf("%d",&value);
    hash_key = value % size;
    for(i = 0; i < size; i++)
    {
        index = (hash_key + i) % size;
        if(hash_table[index] == value)
        {
            printf("\nThe given value %d found at the index : %d",value,index);
            break;
        }
    }
    if(i == size)
        printf("\nThe give value %d not in the hash table.",value);
}


// DELETE FUNCTION

int delete()
{
    int i,value,hash_key,index;
    printf("\nEnter the number : ");
    scanf("%d",&value);
    hash_key = value % size;
    for(i = 0; i < size; i++)
    {
        index = (hash_key + i) % size;
        if(hash_table[index] == value)
        {
            printf("\nThe given number %d is delete in the hash table.",value);
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
                printf("\nWrong option");
            break;
        }
    }
}
