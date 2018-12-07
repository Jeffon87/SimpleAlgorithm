#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#ifndef __ALGRITHMTEST_H__
#define __ALGRITHMTEST_H__

//#define FUNCTEST
#define felixPrint(fmt, args...) printf("[%s:%d] " fmt "\n", __FUNCTION__, __LINE__, ##args)

void PrintCharArray(char *array, unsigned int arrayLength, char *flagStr);
void PrintArray(int *array, unsigned int arrayLength, char *flagStr);
void PrintArrayWithIdx(int *array, int left, int right, char *flagStr);
void myMemCpy(char *a, char *b, int counts, int bPrint);

#ifdef FUNCTEST
void KMP_PatternMatch(void);
#else
void HeapSort(int *a, int size);
void TestMergeSort(void);
void QuickSort(int *a, int left, int right);
void KMP_PatternMatch(const char *inputStr, int inputStrLen, const char *pattern, int patternLen);
#endif

#endif