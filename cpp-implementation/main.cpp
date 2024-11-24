#include "mergeSort.hpp"
#include "parallelMergeSort.hpp"
#include <chrono>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {

    const int SIZE = 10000000;
    std::vector<int> nums(SIZE);
    std::vector<int> nums1(SIZE);

    // Fill nums and nums1 with random values
    for (int i = 0; i < SIZE; ++i) {
        nums[i] = rand() % 1000;
        nums1[i] = rand() % 1000;
    }

    // Pass by reference, not by pointer
    MergeSort mergeSort(nums);
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort.sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergeSortDuration = end - start;
    std::cout << "MergeSort algorithm time taken: " << mergeSortDuration.count()
              << " seconds" << std::endl;

    // Pass by reference, not by pointer
    ParallelMergeSort mergeSort1(nums1);
    start = std::chrono::high_resolution_clock::now();
    mergeSort1.sort();
    end = std::chrono::high_resolution_clock::now();
    mergeSortDuration = end - start;
    std::cout << "Parallel MergeSort algorithm time taken: "
              << mergeSortDuration.count() << " seconds" << std::endl;

    return 0;
}
