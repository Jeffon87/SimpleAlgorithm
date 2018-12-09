objects = MyTest.o MyDataStructure.o MySort.o HeapSort.o mytest_common.o MergeSort.o QuickSort.o KMP.o

mytest : $(objects)
	gcc -g  -Wall -o mytest $(objects)

mytest_common.o : algrithmtest.h
MyTest.o : algrithmtest.h
MyDataStructure.o : algrithmtest.h
MySort.o : algrithmtest.h testarray.h
HeapSort.o : algrithmtest.h
MergeSort.o : algrithmtest.h
QuickSort.o : algrithmtest.h
KMP.o :  algrithmtest.h testarray.h

.PHONY : clean
clean :
	rm mytest $(objects)
