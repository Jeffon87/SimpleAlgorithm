#include "algrithmtest.h"

void PrintArray(int *array, unsigned int arrayLength, char *flagStr)
{
    int i, k;
    int key;

    printf("[%s] The array is:\n", flagStr);
    for(i=0; i<arrayLength; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void PrintArrayWithIdx(int *array, int left, int right, char *flagStr)
{
    int i, k;
    int key;

    printf("[%s] The array is:\n", flagStr);
    for(i=left; i<=right; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}