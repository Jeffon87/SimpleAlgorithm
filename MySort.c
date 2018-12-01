#include "algrithmtest.h"
#include "testarray.h"

void main(int argc, char *argv[])
{
    PrintArray(a_long, A_LONG_LEN, "Before sort...");
    //HeapSort(a_short, A_SHORT_LEN);
    QuickSort(a_long, 0, A_LONG_LEN-1);
    PrintArray(a_long, A_LONG_LEN, "After sort");
    return;
}