#ifndef __MYTEST_COMMON__
#define __MYTEST_COMMON__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define felixPrint(fmt, args...) printf("[%s:%d] " fmt "\n", __FUNCTION__, __LINE__, ##args)

void PrintCharArray(char *array, unsigned int arrayLength, char *flagStr);
void PrintArray(int *array, unsigned int arrayLength, char *flagStr);
void PrintArrayWithIdx(int *array, int left, int right, char *flagStr);
void myMemCpy(char *a, char *b, int counts, int bPrint);

#endif