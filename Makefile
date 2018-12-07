objects = HeapSort.o MySort.o mytest_common.o MergeSort.o QuickSort.o KMP.o

mytest : $(objects)
	gcc -g -o mytest $(objects)

HeapSort.o : algrithmtest.h
MySort.o : algrithmtest.h
mytest_common.o : algrithmtest.h
MergeSort.o : algrithmtest.h
QuickSort.o : algrithmtest.h
KMP.o :  algrithmtest.h testarray.h


.PHONY : clean
clean :
	rm myTest $(objects)
