// IMPLEMENTATION OF COUNT SORT

#include<stdio.h>

// MAIN FUNCTION

int main()
{
    int size,max = 0;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int array[size],sort_array[size];
    printf("\nEnter %d number of element in the array : \n",size);
    for(int i = 0; i < size; i++)
    {
        printf("Element - [%d] : ",i);
        scanf("%d",&array[i]);
        if(max < array[i])
        {
            max = array[i];
        }
    }
    int count_array[max+1];
    
    //  ASSINGING ZERO IN THE COUNT ARRAY
    
    for(int i = 0; i <= max; i++)
    {
        count_array[i] = 0; 
    }

    //  INCERMENTING VALUE IN THE COUNT ARRAY

    for(int i = 0; i < size; i++)
    {
        count_array[array[i]]++;
    }

    for(int i = 1; i <= max; i++)
    {
        count_array[i] = count_array[i] + count_array[i - 1];
    }

    for(int i = 0; i < size; i++)
    {
        count_array[array[i]]--;
        sort_array[count_array[array[i]]] = array[i];
    }

    //  AFTER SORTING

    printf("\nAfter sorting the element in the array are : \n");
    for(int i = 0; i < size; i++)
    {
        printf("Element - [%d] : %d\n",i,sort_array[i]);
    }
    return 0;
}


/*
output : 

Enter the size of the array : 4

Enter 4 number of element in the array : 
Element - [0] : 3
Element - [1] : 2
Element - [2] : 1
Element - [3] : 4

After sorting the element in the array are : 
Element - [0] : 1
Element - [1] : 2
Element - [2] : 3
Element - [3] : 4

*/