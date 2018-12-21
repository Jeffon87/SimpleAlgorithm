//#include "algrithmtest.h"
#include "MyTestCommon.h"
#include "MySort.h"

#define MYARRAYSIZE 100
#define FELIX_DEBUG
int myArray[MYARRAYSIZE] = {0};

typedef enum test_type{
    TESTFUNCTION,
    TESTTIMECONSUMPTION,
} test_type;

typedef long long int llint;

#define TMPARRAYMAXLEN 100
#define LONGARRAYLEN 48
int testIntArrayLong[LONGARRAYLEN] = {3432, 52, 22, 543, 3652, 22, 786, 11234, 43, 325, 532,22,  22, 22, 252, 523,
              52, 22, 543, 3652, 22, 786, 11234, 43, 325, 532,22,  22, 22, 252, 523, 852,
              2, 22, 543, 3652, 22, 786, 11234, 43, 325, 532,22,  22, 22, 252, 523,9
              }; 
int addrTest;
#define CSIZE 4
//int c[CSIZE] = {1, -3, 3, 4, 5, 6, -9, 8}; 
int testIntArrayShort[CSIZE] = {1, -3, 3, 4}; 
int testTmpArray[TMPARRAYMAXLEN] = {0}; 
static int *a;
static int aSize;
static test_type myTestType = TESTTIMECONSUMPTION;
static int compareTimes = 0;
static int swapTimes = 0;
struct ListNode {
    int val;
    struct ListNode *next;
};
int G[5] = {0, 1, 3};

void myMemCpy(char *a, char *b, int counts, int bPrint)
{
    int i = 0;
    if(a == NULL || b == NULL || counts <=0)
        return;
    
    while(counts--)
    {
        if(bPrint == 1)
        {
           printf("myMemCpy: Src[%d] - %d, Dst[%d] - %d\n", i, *(a+i), i, *(b+i));
        }
        *(a+i) = *(b+i);
        i++;
    }
}

//归并排序是将两个有序数列合并成一个有序数列。
//时间复杂度为：

void MergeSort2(int *a, int left, int right, int *b)
{
    int mid  = (left+right)/2;
    int i, j;
    int k = 0;
    //printf("MergeSort2: left - %d, right - %d\n", left, right);
    if(b == NULL || left >= right || b == NULL)
        return;
    else{
        //PrintArrayWithIdx(a, left, right,"MergeSort2-1");
        MergeSort2(a, left, mid, b);
        //PrintArrayWithIdx(a, left, right, "MergeSort2-2");
        MergeSort2(a, mid + 1, right, b);
        //PrintArrayWithIdx(a, left, right, "MergeSort2-3");
        i = left;
        j = mid+1;
        while(1)
        {
            if(i<=mid && j <= right && a[i]>=a[j])
                b[k++] = a[i++];
            else if(i<=mid && j <= right && a[i]<a[j])
                b[k++] = a[j++];
            else if(i>mid && j <= right)
                b[k++] = a[j++];
            else if(i<=mid && j > right)
                b[k++] = a[i++];
            else
                break;
        }

        memcpy(&a[left], b, (size_t)((right-left+1)*sizeof(int)));
        //printf("\n\n");
        return;
    }
}

void TestMergeSort(void)
{
    PrintArray(testIntArrayLong, LONGARRAYLEN, "TestMergeSort-1");
    MergeSort2(testIntArrayLong, 0, LONGARRAYLEN-1, testTmpArray);
    PrintArray(testIntArrayLong, LONGARRAYLEN, "TestMergeSort-3");
}