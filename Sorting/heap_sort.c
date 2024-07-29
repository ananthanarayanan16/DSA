// IMPLEMENTAION OF HEAP SORT

#include <stdio.h>
#define size 10

int array[size];

//  MAIN FUNCTION

int main()
{
    int max = 0, swap, index;
    printf("Enter %d element of the array : \n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Element - [%d] : ", i);
        scanf("%d", &array[i]);
    }

    // SORTING PORTION
    for (int i = 0; i < size; i++)
    {
        max = 0;
        for (int j = 0; j < size - i; j++)
        {
            if (max < array[j])
            {
                max = array[j];
                index = j;
            }
        }
        swap = array[index];
        array[index] = array[0];
        array[0] = swap;

        swap = array[0];
        array[0] = array[size - 1 - i];
        array[size - 1 - i] = swap;
    }

    // AFTER SORTINFG

    printf("\nAfter sorting the give array : \n");
    for(int i = 0; i < size; i++)
    {
        printf("Element - [%d] : %d\n",i,array[i]);
    }
    return 0;
}

/* 

output : 

Enter 10 element of the array : 
Element - [0] : 1
Element - [1] : 10
Element - [2] : 2
Element - [3] : 9
Element - [4] : 3
Element - [5] : 8
Element - [6] : 4
Element - [7] : 7
Element - [8] : 5
Element - [9] : 6

After sorting the give array : 
Element - [0] : 1
Element - [1] : 2
Element - [2] : 3
Element - [3] : 4
Element - [4] : 5
Element - [5] : 6
Element - [6] : 7
Element - [7] : 8
Element - [8] : 9
Element - [9] : 10

*/
