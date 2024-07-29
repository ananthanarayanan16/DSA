// IMPLEMENTATION OF BUCKET SORT

#include <stdio.h>
#define size 10

int bucket[size][size], array[size], index1, index2, temp, count = 0;

//  MAIN FUNCTION

int main()
{
    // int in;
    printf("\nEnter %d element in the array : ", size);
    for (int i = 0; i < size; i++)
    {
        printf("\nElement - [%d] : ", i);
        scanf("%d", &array[i]);
    }

    //  ELEMENT DISTRIBUTE IN THE BUCKET

    for (int i = 0; i < size; i++)
    {
        index1 = array[i] / size;
        if (index1 >= size)
        {
            index1 = size - 1;
        }
        index2 = 0;
        for (int j = 0; j < size; j++)
        {
            if (bucket[index1][index2] == 0)
            {
                bucket[index1][index2] = array[i];
                break;
            }
            else
            {
                index2++;
            }
        }
    }

    // USING SELECTION SORT TO SORT THE BUCKET

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (bucket[i][j] != 0)
            {
                for (int k = j + 1; k < size; k++)
                {
                    if(bucket[i][k] == 0)
                    {
                        break;
                    }
                    else if (bucket[i][j] > bucket[i][k])
                    {
                        temp = bucket[i][j];
                        bucket[i][j] = bucket[i][k];
                        bucket[i][k] = temp;
                    }
                }
            }
        }
    }

/*
    // PRINT THE BUCKET ELEMENT

    printf("\nBucket elements : \n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("n = %d  ", bucket[i][j]);
        }
        printf("\n");
    }
*/

    // INSERT THE BUCKET ELEMENT IN THE ARRAY

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (bucket[i][j] != 0)
            {
                array[count++] = bucket[i][j];
                // count++;
            }
        }
    }

    //   AFTER SORTING

    printf("\nAfter the array sorted : \n");
    for (int i = 0; i < size; i++)
    {
        printf("\nElement - [%d] : %d\n", i, array[i]);
    }
    return 0;
}