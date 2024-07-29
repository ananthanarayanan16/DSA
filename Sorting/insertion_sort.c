// IMPLEMANTAION OF INSERTION SORT

#include <stdio.h>

// MAIN FUCNTION

int main()
{
    int size, key, temp, j, i;
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    int array[size];
    printf("\nEnter %d number of element in the array : ", size);
    for (i = 0; i < size; i++)
    {
        printf("\nElement - [%d] : ", i);
        scanf("%d", &array[i]);
    }

    // SORTING PORTION

    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    // AFTER SORTING

    printf("\nAfter sorting the given array : \n");
    for (i = 0; i < size; i++)
    {
        printf("Elemnent - [%d] : %d\n", i, array[i]);
    }

    return 0;
}



/*
output : 

Enter the size of the array : 5

Enter 5 number of element in the array : 
Element - [0] : 5

Element - [1] : 1

Element - [2] : 9

Element - [3] : 2

Element - [4] : 4

After sorting the given array : 
Elemnent - [0] : 1
Elemnent - [1] : 2
Elemnent - [2] : 4
Elemnent - [3] : 5
Elemnent - [4] : 9

*/