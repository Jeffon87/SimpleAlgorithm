#include "../common/MyTestCommon.h"
#include "AlgorithmCommon.h"

/*
 * 1, 数据山脉指的是形如: 12342，最小的山脉长度是3，山脉为：142。
 * 2, 山峰处最高，高点处只能有一个高点。山峰左边逐步上升，山峰右边逐步下降。所以形如12344321不能算一个山脉。
 * 3, 例如： 123343452中最长山脉为3452，长度为4。
 * 问题：给出一串数字串，找出其中最长山脉的长度。
 * 原型为： int LongestMountain(int *array, int arraySize)
 */
#define UP 1
#define DOWN 2
#define UNSET 0

/*
 * 依次增加一个元素，更新最大peak长度。
 * 1，任何时候要么是在山峰上升期，要么在山峰下降区，相等的时候山峰归零。
 * 2，根据当前山峰状态以及最新元素去更新最长山脉长度。
 */
int LongestMountain_1(int *array, int arraySize)
{
  static int mountainLenTmp = 0;
  /* Up status can be 1-up, 2-down, 0-unset */
  static int up = UNSET;
  int longestMountainLen = 0;

  if(NULL == array || 2 > arraySize)
  {
    printf("LongestMountain_1: invalid parameters!\n");
  } else if(2 == arraySize && array[0] < array[1]){
    up = UP;
	mountainLenTmp = 2;
  } else{
    longestMountainLen = LongestMountain_1(array, arraySize-1);
	switch(up){
      case UP:
	  	if(array[arraySize-1] < array[arraySize-2])
  		{
  		  up = DOWN;
          mountainLenTmp = mountainLenTmp +1;
		  longestMountainLen = longestMountainLen>mountainLenTmp?longestMountainLen:mountainLenTmp;
  		}else if(array[arraySize-1] > array[arraySize-2]){
          mountainLenTmp = mountainLenTmp +1;
		}else{
          up = UNSET;
		}
	  	break;
	  case DOWN:
	  	if(array[arraySize-1] < array[arraySize-2])
  		{
          mountainLenTmp = mountainLenTmp +1;
		  longestMountainLen = longestMountainLen>mountainLenTmp?longestMountainLen:mountainLenTmp;
  		}else if(array[arraySize-1] > array[arraySize-2]){
		  up = UP;
          mountainLenTmp = 2;
		}else{
          up = UNSET;
		}
	  	break;
	  case UNSET:
	  	if(array[arraySize-1] > array[arraySize-2]){
		  up = UP;
          mountainLenTmp = 2;
		}
	  	break;
	  default:
	  	printf("Should not be here!\n");
	  	break;
	}
  }

  return longestMountainLen;
}

int LongestMountain_2(int *array, int arraySize)
{
  int mountainLenTmp = 0;
  /* Up status can be 1-up, 2-down, 0-unset */
  int up = UNSET;
  int longestMountainLen = 0;
  int i;

  if(3 > arraySize)
  	return 0;

  for(i = 1; i < arraySize; i++)
  {
    switch(up){
      case UP:
	  	if(array[i-1] < array[i]){
		  mountainLenTmp++;
		} else if(array[i-1] > array[i]){
		  mountainLenTmp++;
          longestMountainLen = longestMountainLen>mountainLenTmp?longestMountainLen:mountainLenTmp;
		  up = DOWN;
		} else{
          mountainLenTmp = 0;
		  up = UNSET;
		}
	  	break;
	  case DOWN:
	  	if(array[i-1] < array[i]){
          up = UP;
		  mountainLenTmp = 2;
		} else if(array[i-1] > array[i]){
		  mountainLenTmp++;
          longestMountainLen = longestMountainLen>mountainLenTmp?longestMountainLen:mountainLenTmp;
		} else{
          mountainLenTmp = 0;
		  up = UNSET;
		}
	  	break;
	  case UNSET:
	  	if(array[i-1] < array[i]){
          up = UP;
		  mountainLenTmp = 2;
		}
	  	break;
	  default:
	    break;
	}
  }

  return longestMountainLen;
}

void TestLongestMountain(void* input)
{
  int mountainLen = 0;

  PrintArray(longestMountain_2, ARRAYLENGTH_2, "LongestMountain_1");
  mountainLen = LongestMountain_1(longestMountain_2, ARRAYLENGTH_2);

  printf("[TestLongestMountain]LongestMountain_1: the longest mountain peak is %d\n", mountainLen);

  PrintArray(longestMountain_2, ARRAYLENGTH_2, "LongestMountain_2");
  mountainLen = LongestMountain_2(longestMountain_2, ARRAYLENGTH_2);

  printf("[TestLongestMountain]LongestMountain_2: the longest mountain peak is %d\n", mountainLen);
}
