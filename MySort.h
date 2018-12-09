#ifndef __MYSORT_H__
#define __MYSORT_H__

#ifdef FUNCTEST
void KMP_PatternMatch(void);
#else
void HeapSort(int *a, int size);
void TestMergeSort(void);
void QuickSort(int *a, int left, int right);
void KMP_PatternMatch(const char *inputStr, int inputStrLen, const char *pattern, int patternLen);
#endif

#endif