run:
	@g++ -std=c++11 -o parallel_sort src/main.cpp src/mergeSort.cpp src/parallelMergeSort.cpp -pthread
	@./parallel_sort
