//   IMPLEMENATAION OF QUIK SORT

#include <stdio.h>
#include <stdlib.h>
#define size 10

int array[size], pivot,temp;

// FUNCTION DECLERATION 

int quick_sort(int [], int, int);
int partition(int [], int ,int);


// QUICK SORT FUNCTION

int quick_sort(int array[], int low, int high)
{
    // int pivot;
    if (low < high)
    {
        pivot = partition(array, low, high);
        quick_sort(array, low, pivot - 1);
        quick_sort(array, pivot + 1, high);
    }
    return 0;
}


//   PARTITON FUNCTION

int partition(int array[], int low , int high)
{   
    pivot = array[high];
    int i = (low - 1);
    for(int j = low; j <= high- 1; j++)
    {
        if(array[j] < pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
}



// MAIN FUNCTION

int main()
{
    printf("Enter %d number of element in the array : \n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Element - [%d] : ", i);
        scanf("%d", &array[i]);
    }

    // CALLING SORT FUNCTION

    quick_sort(array, 0, 9);

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

Enter 10 number of element in the array : 
Element - [0] : 10
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