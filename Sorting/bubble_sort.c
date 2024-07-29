// IMPLEMENTATION OF BUBBLE SORT

#include<stdio.h>

int main()
{
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int array[size],temp;
    printf("Enter %d number of element in the array : \n",size);
    for(int i = 0; i < size; i++)
    {
        printf("\nElement - [%d] : ",i);
        scanf("%d",&array[i]);
    }

    //  SORTING PORTION

    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-1; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    // AFTER SORTING

    printf("\nThe sorted array is : \n");
    for(int i = 0; i < size; i++)
    {
        printf("Element - [%d] : %d\n",i,array[i]);
    }
    return 0;
}