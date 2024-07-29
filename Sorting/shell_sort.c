// IMPLEMENTATION OF SHELL SORT

#include <stdio.h>
#include <stdlib.h>

// MAIN FUNCTION

int main()
{
    int size, intervel, swap, n = 2,i,j;
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    int array[size];
    printf("\nEnter %d number in the array :\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Element - [%d] : ", i);
        scanf("%d", &array[i]);
    }

    // SORTING PORTION

    while (1)
    {
        intervel = size / n;
        if(intervel == 0)
        {
            break;
        }
        for (i = intervel; i < size; i++)
        {
            swap = array[i];
            for (j = i; j >= intervel && array[j - intervel] > swap; j -= intervel)
            {
                array[j] = array[j - intervel];
            }
            array[j] = swap;
        }
        n = n *2;
    }

    /*   while(1)
    {
        intervel = size / n;
        for(int i = intervel; i < size; i++)
        {
            if (array[i - intervel] > array[i])
            {
                swap = array[i - intervel];
                array[i - intervel] = array[i];
                array[i] = swap;
            }
        }
        if (intervel > 0)
        {
            n = n *2;
        }
        else
        {
            break;
        }
    }
*/
    // AFTER SORTING

    printf("\nAfter sorting the given array : \n");
    for(int i = 0; i < size; i++)
    {
        printf("Element - [%d] : %d\n",i,array[i]);
    }
    return 0;
}

/*
output :

Enter the size of the array : 6

Enter 6 number in the array :
Element - [0] : 6
Element - [1] : 1
Element - [2] : 5
Element - [3] : 2
Element - [4] : 4
Element - [5] : 3

After the given array : 
Element - [0] : 1
Element - [1] : 2
Element - [2] : 3
Element - [3] : 4
Element - [4] : 5
Element - [5] : 6

*/