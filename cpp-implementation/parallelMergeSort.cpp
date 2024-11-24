#include "parallelMergeSort.hpp"
#include <algorithm>
#include <thread>
#include <future>

ParallelMergeSort::ParallelMergeSort(std::vector<int>& nums) : nums(nums) {}

ParallelMergeSort::~ParallelMergeSort() {}

void ParallelMergeSort::recursiveSort(int left, int right) {
    const int THRESHOLD = 5000;

    // If the array size is below the threshold, use standard sort to avoid thread overhead
    if (right - left < THRESHOLD) {
        std::sort(nums.begin() + left, nums.begin() + right + 1);
        return;
    }

    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    // Using async instead of creating explicit threads
    auto future_1 = std::async(std::launch::async, [this, left, mid] { this->recursiveSort(left, mid); });
    auto future_2 = std::async(std::launch::async, [this, mid, right] { this->recursiveSort(mid + 1, right); });

    // Wait for both halves to be sorted
    future_1.get();
    future_2.get();

    merge(left, mid, right);
}

void ParallelMergeSort::merge(int left, int mid, int right) {
    int i = left, j = mid + 1;
    std::vector<int> result; // Temporary vector for merging

    // Merge two halves into the result vector
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            result.push_back(nums[i]);
            i++;
        } else {
            result.push_back(nums[j]);
            j++;
        }
    }

    // If there are remaining elements in the left half
    while (i <= mid) {
        result.push_back(nums[i]);
        i++;
    }

    // If there are remaining elements in the right half
    while (j <= right) {
        result.push_back(nums[j]);
        j++;
    }

    // Copy the merged result back into the original vector
    for (int k = 0; k < result.size(); k++) {
        nums[left + k] = result[k];
    }
}

void ParallelMergeSort::sort() {
    if (nums.empty()) {
        return;  // Gracefully handle the empty vector case
    }

    // Start the sorting process using async to parallelize
    auto future = std::async(std::launch::async, [this] { this->recursiveSort(0, nums.size() - 1); });
    future.get();
}
