#include "mergeSort.hpp"
#include "parallelMergeSort.hpp"
#include <chrono>
#include <iostream>

int main(int argc, char *argv[]) {

  const int SIZE = 1000;
  std::vector<int> nums(SIZE);
  std::vector<int> nums1(SIZE);

  for (int i = 0; i < SIZE; ++i) {
    nums[i] = rand() % 1000;
    nums1[i] = rand() % 1000;
  }

  MergeSort *mergeSort = new MergeSort(&nums);
  auto start = std::chrono::high_resolution_clock::now();
  mergeSort->sort();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> mergeSortDuration = end - start;
  std::cout << "MergeSort algorithm time taken: " << mergeSortDuration.count()
            << "seconds" << std::endl;

  delete mergeSort;

  ParallelMergeSort *mergeSort1 = new ParallelMergeSort(&nums1);
  start = std::chrono::high_resolution_clock::now();
  mergeSort1->sort();
  end = std::chrono::high_resolution_clock::now();
  mergeSortDuration = end - start;
  std::cout << "Parallel MergeSort algorithm time taken: "
            << mergeSortDuration.count() << "seconds" << std::endl;

  delete mergeSort1;

  return 0;
}
