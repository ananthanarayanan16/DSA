// IMPLEMENTATION OF SELECTION SORT...

#include<stdio.h>

int main()
{
    int size;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    int array[size],temp;
    printf("\nEnter %d element in the array.\n",size);
    for(int i = 0; i < size; i++)
    {
        printf("\nElement - [%d] : ",i);
        scanf("%d",&array[i]);
    }

    //  SORTING PORTION

    for(int i = 0; i < size; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
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