#include "mergeSort.h"
#include "main.h"

void merge(int *arr, int *arr1, int *arr2, int low, int hi) {
  if (low < hi) {
    int mid = (low + hi) / 2;

    merge(arr, arr1, arr2, low, mid);
    merge(arr, arr1, arr2, mid + 1, hi);
    sort(arr, arr1, arr2, low, hi, mid);
  }
}

void sort(int *arr, int *arr1, int *arr2, int low, int hi, int mid) {
  // Declaration
  int idx1, idx2, i, j, k;

  // Initialization
  idx1 = mid - low + 1;
  idx2 = hi - mid;

  for (i = 0; i < idx1; i++) {
    arr1[i] = arr[low + i];
  }

  for (j = 0; j < idx2; j++) {
    arr2[j] = arr[mid + 1 + j];
  }

  i = 0;
  j = 0;
  k = low;

  // sort
  while (i < idx1 && j < idx2) {
    if (arr1[i] <= arr2[j]) {
      arr[k++] = arr1[i++];
    } else {
      arr[k++] = arr2[j++];
    }
  }

  // add remaining elements
  while (i < idx1) {
    arr[k++] = arr1[i++];
  }

  while (j < idx2) {
    arr[k++] = arr2[j++];
  }
}
