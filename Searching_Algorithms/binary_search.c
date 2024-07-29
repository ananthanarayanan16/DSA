//  IMPLEMENTAION OF BINARY SEARCH

#include<stdio.h>

int size;

//  FUCNTION DECLARETION

int search(int [], int);

// MAIN FUNCTION

int main()
{
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    
    // DECLARETION OF ARRAY
    int array[size],num;

    printf("\nGive the array element in ascending or descending order.\n");
    printf("\nEnter %d number of element in the array :\n",size);
    for(int i = 0; i < size; i++)
    {
        printf("\nElement - [%d] : ",i);
        scanf("%d",&array[i]);
    }
    
    //  GET SEARCHING ELEMENT

    printf("\nEnter a number for search : ");
    scanf("%d",&num);

    // CALLING SEARCHING FUCNTION

    if(search(array,num) == -1)
    {
        printf("\nThe given number %d is not found in the array.\n",num);
    }
    else
    {
        printf("\nThe given number %d is found in the index : %d\n",num,search(array,num));
    }
    return 0;
}

// FUNCTION DEFINITION

int search(int array[],int num)
{
    int l = 0,r = size-1,m;
    while(l <= r)
    {
        m = (l + r) / 2;
        if(array[m] == num)
        {
            return m;
        }
        else if(num > array[m])
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}


/*
output : 

Enter the size of the array : 5

Give the array element in ascending or descending order.

Enter 5 number of element in the array :

Element - [0] : 5

Element - [1] : 4

Element - [2] : 3

Element - [3] : 2

Element - [4] : 1

Enter a number for search : 0

The given number 0 is not found in the array.

*/