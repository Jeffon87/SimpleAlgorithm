objects = MyTest.o HeapSort.o SelectSort.o QuickSort.o MyTestCommon.o MergeSort.o BubleSort.o TestArray.o
## MergeSort.o QuickSort.o

ssh_mytest : $(objects)
	gcc -g  -Wall -o ssh_mytest $(objects)

##MyTestCommon.o : MyTestCommon.h
##MyTest.o : MyTestCommon.h
##MyDataStructure.o : MyTestCommon.h
##MySort.o : MyTestCommon.h
##HeapSort.o : MyTestCommon.h
##MergeSort.o : MyTestCommon.h
##QuickSort.o : MyTestCommon.h
##KMP.o :  MyTestCommon.h

.PHONY : clean
clean :
	rm ssh_mytest $(objects)
