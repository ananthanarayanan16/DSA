//  IMPLEMENTATION OF THE MERGE SORT

#include <stdio.h>
#include <stdlib.h>
#define size 10

// int merge_sort(int [],int, int);
// int merge(int [],int, int, int);

int array[size], temp[size];

//   MERGE SORT FUNCTION

int merge_sort(int array[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = (start + end) / 2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
    return 0;
}

// MERGE FUNCTION

int merge(int array[], int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end)
    {
        if (array[i] > array[j])
        {
            temp[k++] = array[j++];
        }
        else
        {
            temp[k++] = array[i++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = array[i++];
    }

    while (j <= end)
    {
        temp[k++] = array[j++];
    }

    for (int i = start; i <= end; i++)
    {
        array[i] = temp[i];
    }
    return 0;
}

//  MAIN FUNCTION

int main()
{
    printf("\nEnter %d number in the array : \n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Element - [%d] : ", i);
        scanf("%d", &array[i]);
    }

    // CALLING THE SORT FUNCTION

    merge_sort(array, 0, size - 1);

    //  AFTER THE SORTING

    printf("\nAfter sorting the given array : \n");
    for (int i = 0; i < size; i++)
    {
        printf("Element - [%d] : %d\n", i, array[i]);
    }
    return 0;
}


/*

output :

Enter 10 number in the array : Element - [0] : 10
Element - [1] : 1
Element - [2] : 9
Element - [3] : 2
Element - [4] : 8
Element - [5] : 3
Element - [6] : 7
Element - [7] : 4
Element - [8] : 6
Element - [9] : 5

After sorting the given array : 
Element - [0] : 1
Element - [1] : 9
Element - [2] : 2
Element - [3] : 8
Element - [4] : 3
Element - [5] : 7
Element - [6] : 4
Element - [7] : 6
Element - [8] : 5
Element - [9] : 10

*/