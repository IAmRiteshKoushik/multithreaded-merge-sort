run:
	@g++ -std=c++11 -o parallel_sort cpp-implementation/main.cpp cpp-implementation/mergeSort.cpp cpp-implementation/parallelMergeSort.cpp -pthread
	@./parallel_sort
