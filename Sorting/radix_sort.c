// IMPLEMENTATION OF RADIX SORT

#include <stdio.h>
#define size 10

int bucket[size][size], array[size], index_1, index_2 = 0, array_index, count = 0, max = 0;

// DIGIT FUNCTION

int digit(int count, int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            index_1 = num % 10;
            num = num / 10;
        }
        return index_1;
    }
}

// MAIN FUNCTION

int main()
{
    printf("Enter %d element in the array : \n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Element - [%d] : ", i);
        scanf("%d", &array[i]);
        if (max < array[i])
        {
            max = array[i];
        }
    }
 
    // ASSIGNING -1 IN THE BUCKET ARRAY 

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            bucket[i][j] = -1;
        }
    }

    //   SORTING PORTION

    while (max > 0)
    {
        count++;

        // DISTRIBUTING ARRAY ELEMENT IN THE BUCKET ARRAY
    
        for (int i = 0; i < size; i++)
        {
            index_1 = digit(count, array[i]);
            index_2 = 0;
            for (int j = 0; j < size; j++)
            {
                if (bucket[index_1][index_2] == -1)
                {
                    bucket[index_1][index_2] = array[i];
                    break;
                }
                else
                {
                    index_2++;
                }
            }
        }
    
        // ASSIGNING SORTED BUCKET ELEMENT IN THE ARRAY

        array_index = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (bucket[i][j] == -1)
                {
                    break;
                }
                else
                {
                    array[array_index++] = bucket[i][j];
                    bucket[i][j] = -1;
                }
            }
        }

        max = max / 10;
    }

    //  AFTER SORTING

    printf("\nAfter sort the given array : \n");
    for (int i = 0; i < size; i++)
    {
        printf("Element - [%d] : %d\n", i, array[i]);
    }
    return 0;
}

/*

output : 
Enter 10 element in the array : 
Element - [0] : 99
Element - [1] : 1
Element - [2] : 0
Element - [3] : 22
Element - [4] : 876
Element - [5] : 34
Element - [6] : 76
Element - [7] : 45
Element - [8] : 655
Element - [9] : 567

After sort the given array : 
Element - [0] : 0
Element - [1] : 1
Element - [2] : 22
Element - [3] : 34
Element - [4] : 45
Element - [5] : 76
Element - [6] : 99
Element - [7] : 567
Element - [8] : 655
Element - [9] : 876

*/