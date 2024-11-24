#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

class MergeSort {
private:
    std::vector<int>& nums;
    std::vector<int> temp; // Temporary vector for merging

public:
    MergeSort(std::vector<int>& nums);
    ~MergeSort();
    void sort();
    void recursiveSort(int left, int right);
    void merge(int left, int mid, int right);
};

#endif
