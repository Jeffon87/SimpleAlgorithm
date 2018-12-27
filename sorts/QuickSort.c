#include "SortsCommon.h"

//1，快速排序是选择一个参考元素。将数组分为两个部分，每个部分依次排列成序。然后
//2，将数组分为两个部分，左侧元素均不小于参考元素，右侧元素均不大于参考元素。
//3，通过递归的方式知道两侧元素数列均有序之后，整个数列成有序。
//4，需要注意的是在进行分组的时候，交换元素位置只发生在元素大小不相等的时候。
//5， 快速排序是一种不稳定排序方式。
static void QuickSort(int *a, int left, int right)
{
    int tmp = a[left];
    int idxLeft = left;
    int idxRight = right;
    int idxMid;
    
    printf("QuickSort: left - %d, right - %d\n", left, right);
    if(a == NULL || left >= right && right >= 0)
        return;
    else{
        while(idxLeft < idxRight)
        {
            printf("--QuickSort: idxLeft - %d, idxRight - %d\n", idxLeft, idxRight);
            while(idxLeft < idxRight && idxRight >= 0)
                if(a[idxRight]>tmp){
                    a[idxLeft++] = a[idxRight];
                    break;
                }
                else
                    idxRight--;
            printf("----QuickSort1: idxLeft - %d, idxRight - %d\n", idxLeft, idxRight);

            while(idxLeft < idxRight && idxRight >= 0)
                if(a[idxLeft]<tmp){
                    a[idxRight--] = a[idxLeft];
                    break;
                }
                else
                    idxLeft++;
            printf("----QuickSort2: idxLeft - %d, idxRight - %d\n", idxLeft, idxRight);

            if(idxLeft >= idxRight)
            {
                a[idxLeft] = tmp;
                idxMid = idxLeft;
                break;
            }
            printf("----QuickSort-3: idxLeft - %d, idxRight - %d\n", idxLeft, idxRight);

        }

        QuickSort(a, left, idxMid);
        QuickSort(a, idxMid+1, right);
    }
}

void TestQuickSort(void)
{
    printf("%s: TBD\n", __FUNCTION__);
}