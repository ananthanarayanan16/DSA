// IMPLEMENTAION OF LINEAR SEARCH ALGORITHM

#include<stdio.h>
#define size 10

int search(int [], int);

// MAIN FUCTION

int main()
{
    int array[size],num;
    printf("Enter %d number in the array.\n",size);
    for(int i = 0; i < size; i++)
    {
        printf("Index-[%d] : ",i);
        scanf("%d",&array[i]);
    }

    printf("\nEnter a number for search : ");
    scanf("%d",&num);

    if(search(array,num) == 0)
    {
        printf("\nThe given number %d is not present in the array.\n",num);
    }
    else
    {
        printf("\nThe given number %d is present in the array.\n",num);
    }
    return 0;
}


// SEARCH FUNCTION

int search(int array[],int n)
{
    for(int i = 0; i < size; i++)
    {
        if(n == array[i])
        {
            return 1;
        }
    }
    return 0;
}


/*

output : 

Enter 10 number in the array.
Index-[0] : 12
Index-[1] : 90
Index-[2] : 23
Index-[3] : 98
Index-[4] : 34
Index-[5] : 87
Index-[6] : 45
Index-[7] : 76
Index-[8] : 56
Index-[9] : 76

Enter a number for search : 12

The given number 12 is present in the array.

*/