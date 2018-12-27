#include "SortsCommon.h"

//堆是一个近似完全二叉树的结构，并且满足堆积性质：即：子节点的键值或索引总是大于/小于父节点。
//堆通常是用数组来实现的，因为是完全二叉树，所以每个元素可以通过索引来随机访问。
//最大堆，父节点总是大于所有子节点，并且左子树总是大于右子树。排序完成，通过中序遍历打印出有序数列。
void Swap(int *a, int *b)
{
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

//左右子树都是最大堆，新增根节点后重建最大堆。新增根节点索引为start。
void MaxHeapSort(int *a, int start, int end)
{
    int f = start;//父节点
    int s = 2*f +1;//左子节点
    
    while(s<=end)
    {
        if(s+1<=end && a[s] < a[s+1])
            s++;
        
        if(a[f] < a[s])
        {
            Swap(&a[f], &a[s]);
            f = s;
            s = 2*f+1;
        }
        else
            break;
    }
}

//时间复杂度为NlogN
void HeapSort(int *a, int size)
{
    int i;
    //创建一个初始堆，即所有父节点大于/等于其子节点。
    //此处时间复杂度为NlogN
    for(i=(size-1)/2; i>=0; i--)
        MaxHeapSort(a, i, size-1);
    
    //创建好了初始堆，进行堆排序。堆排序每次将根节点得到的最大值交换到最末尾未排序的叶子节点。
    //所以交换次数为size-1次。
    //此处时间复杂度为NlogN
    for(i=size-1; i>0; i--)
    {
        Swap(&a[0], &a[i]);
        MaxHeapSort(a, 0, i-1);
    }
}

void TestHeapSort(void)
{
    //HeapSort(a_short, A_SHORT_LEN);
    printf("%s: TBD\n", __FUNCTION__);
}