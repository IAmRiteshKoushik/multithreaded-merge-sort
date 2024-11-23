#include "parallelMergeSort.h"
#include "main.h"
#include "mergeSort.h"

void *parallelMerge(void *args) {

  struct args *curr1, *curr2;
  int mid, low, hi, *arr1, *arr2, *arr;
  int threshold;
  pthread_t t1, t2;

  // Initialization
  curr1 = args;
  curr2 = args;
  low = curr1->low;
  hi = curr1->hi;
  arr = curr1->arr;
  arr1 = curr1->arr1;
  arr2 = curr1->arr2;

  // set threshold
  threshold = 5000;

  // if array size less than threshold
  if (hi - low < threshold) {
    merge(arr, arr1, arr2, low, hi);
    return NULL;
  }

  if (low < hi) {
    mid = (low + hi) / 2;

    // initalize curr1 and curr2 for left and right part of merge sort
    curr1->hi = mid;
    curr2->low = mid + 1;

    // create the threads
    pthread_create(&t1, NULL, parallelMerge, curr1);
    pthread_create(&t2, NULL, parallelMerge, curr2);

    // wait for threads to end
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Declaration for sort part of code
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
}
