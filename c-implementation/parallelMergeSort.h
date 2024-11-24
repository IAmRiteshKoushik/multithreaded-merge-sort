#ifndef PARALLEL_MERGE_SORT_H
#define PARALLEL_MERGE_SORT_H

struct args {
  int *arr;
  int *arr1;
  int *arr2;
  int low;
  int hi;
};

void *parallelMerge(void *args);

#endif // !PARALLEL_MERGE_SORT_H
