#ifndef PARALLELMERGESORT_H
#define PARALLELMERGESORT_H

#include <vector>
#include <future>

class ParallelMergeSort {
private:
    std::vector<int>& nums;

    void recursiveSort(int left, int right);
    void merge(int left, int mid, int right);

public:
    ParallelMergeSort(std::vector<int>& nums);
    ~ParallelMergeSort();
    void sort();
};

#endif
