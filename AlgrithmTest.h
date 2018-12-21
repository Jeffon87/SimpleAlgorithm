#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#ifndef __ALGRITHMTEST_H__
#define __ALGRITHMTEST_H__

//#define FUNCTEST

/* Test types */
/* 1, Sorts */
void MySort(void);

#ifdef FUNCTEST
void KMP_PatternMatch(void);
#else
void HeapSort(int *a, int size);
void TestHeapSort(void);
void TestMergeSort(void);
void QuickSort(int *a, int left, int right);
void TestQuickSort(void);
void TestBubleSort(void);
void TestSelectSort(void);
void KMP_PatternMatch(const char *inputStr, int inputStrLen, const char *pattern, int patternLen);
#endif

/* 2, Data structure. */
void MyDataStructure(void);


#endif