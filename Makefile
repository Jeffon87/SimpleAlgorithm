objects = HeapSort.o MySort.o mytest_common.o MergeSort.o QuickSort.o

mytest : $(objects)
	gcc -g -o mytest $(objects)

HeapSort.o : algrithmtest.h
MySort.o : algrithmtest.h
mytest_common.o : algrithmtest.h
MergeSort.o : algrithmtest.h
QuickSort.o : algrithmtest.h



.PHONY : clean
clean :
	rm myTest $(objects)
