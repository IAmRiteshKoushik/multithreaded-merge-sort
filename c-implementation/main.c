#include "main.h"
#include "mergeSort.h"
#include "parallelMergeSort.h"

int main() {
  // Declaration
  int i;
  int *arr, *arr1, *arr2;
  struct args arg1;
  clock_t start, end;

  // Initialization
  srand(time(NULL));

  // create array
  arr = malloc(SIZE * sizeof(int));
  arr1 = malloc(SIZE * sizeof(int));
  arr2 = malloc(SIZE * sizeof(int));

  // assign struct
  arg1.hi = SIZE - 1;
  arg1.low = 0;
  arg1.arr = arr;
  arg1.arr1 = arr1;
  arg1.arr2 = arr2;

  // Fill array elements
  for (i = 0; i < SIZE; i++) {
    arr[i] = rand() % 1000;
  }

  // merge sort
  start = clock();
  merge(arr, arr1, arr2, 0, SIZE - 1);
  end = clock();

  // print time taken
  printf("Normal Merge: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

  // parallel merge sort
  start = clock();
  parallelMerge(&arg1);
  end = clock();

  // print time taken
  printf("Parallel Merge: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

  // free memory space
  free(arr);
  free(arr1);
  free(arr2);

  return 0;
}
