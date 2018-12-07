#include "algrithmtest.h"
#ifndef FUNCTEST
#include "testarray.h"
#endif

void main(int argc, char *argv[])
{
#ifdef FUNCTEST
    KMP_PatternMatch();
#else
    char *inputStr = NULL;
    inputStr = COMBINESTR(patternString,1);
    //PrintArray(a_long, A_LONG_LEN, "Before sort...");
    //HeapSort(a_short, A_SHORT_LEN);
    //QuickSort(a_long, 0, A_LONG_LEN-1);
    //PrintArray(a_long, A_LONG_LEN, "After sort");
    
    KMP_PatternMatch(patternString6, 9, "ab", 2);
    //printf("string name is %s\n", COMBINESTR(patternString,1));
#endif
    return;
}