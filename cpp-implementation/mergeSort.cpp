#include "mergeSort.hpp"
#include <cstdlib>

MergeSort::MergeSort(std::vector<int>& nums) : nums(nums), temp(nums.size()) {}

MergeSort::~MergeSort() {}

void MergeSort::recursiveSort(int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    // First, sort both halves
    recursiveSort(left, mid);
    recursiveSort(mid + 1, right);

    // Merge sorted halves in place
    merge(left, mid, right);
}

void MergeSort::merge(int left, int mid, int right) {
    int i = left, j = mid + 1;
    int k = left;

    // Merge two halves into the temp vector
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    // If there are remaining elements in the left half
    while (i <= mid) {
        temp[k++] = nums[i++];
    }

    // If there are remaining elements in the right half
    while (j <= right) {
        temp[k++] = nums[j++];
    }

    // Copy the merged result back into the original vector
    for (int k = left; k <= right; k++) {
        nums[k] = temp[k];
    }
}

void MergeSort::sort() {
    if (nums.empty()) {
        return;  // Gracefully handle the empty vector case
    }
    recursiveSort(0, nums.size() - 1);
}
