public class MergeSort {
    public static void mergeSort(int[] arr) {
        if (arr.length > 1) {
            int mid = arr.length / 2;

            int[] left = new int[mid];
            int[] right = new int[arr.length - mid];

            // Dividing the array into two
            System.arraycopy(arr, 0, left, 0, mid);
            System.arraycopy(arr, mid, right, 0, arr.length - mid);

            // Recursively calling mergeSort on both half's of the array
            mergeSort(left);
            mergeSort(right);

            // Merging the sorted left and sorted right array
            merge(left, right, arr);
        }
    }
    public static void merge(int [] left, int[] right, int[] arr) {
        // i -> tracks the index of left, j -> tracks the index of right, j -> tracks the index of array
        int i = 0, j = 0, k = 0;

        // Merging elements from left and right array into a single array while maintaining order
        while (i < left.length && j < right.length) {
                if (left[i] < right[j]) {
                    arr[k++] = left[i++];
                }
                else {
                    arr[k++] = right[j++];
                }
            }

        // if right array is empty, copy the remaining elements from left array
        while (i < left.length) {
                arr[k++] = left[i++];
            }

        // if left array is empty, copy the remaining elements from right array
        while (j < right.length) {
                arr[k++] = right[j++];
            }
    }

    public static void main(String[] args) {
        // Initial unsorted array
        int[] arr = new int[] {5, 4, 3, 2, 1};

        // Benchmark for Normal Merge Sort
        long startTime = System.nanoTime();
        mergeSort(arr);
        long endTime = System.nanoTime();

        // Printing sorted array
        System.out.print("Sorted Array : ");
        for(int i : arr) {
            System.out.print(i + " ");
        }

        System.out.println("\nTime taken for normal merge sort : " + (endTime - startTime) + "ns");
    }
}

