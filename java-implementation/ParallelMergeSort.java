import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveAction;

public class ParallelMergeSort {

    // Threshold to switch to normal merge sort
    private static final int THRESHOLD = 5000;

    public static void parallelMergeSort(int[] arr) {
        SortTask sortTask = new SortTask(arr);
        ForkJoinPool pool = new ForkJoinPool();
        pool.invoke(sortTask);
    }

    public static class SortTask extends RecursiveAction {
        private final int[] arr;

        public SortTask(int[] arr) {
            this.arr = arr;
        }

        @Override
        protected void compute() {
            if (arr.length > 1) {
                // If array is larger than threshold, proceed with parallel merge sort
                if (arr.length > THRESHOLD) {
                    int mid = arr.length / 2;

                    int[] left = new int[mid];
                    int[] right = new int[arr.length - mid];

                    System.arraycopy(arr, 0, left, 0, mid);
                    System.arraycopy(arr, mid, right, 0, arr.length - mid);

                    // Create subtasks for the two halves
                    SortTask first = new SortTask(left);
                    SortTask second = new SortTask(right);

                    // Invoke both tasks in parallel
                    invokeAll(first, second);

                    // Merge the two halves
                    MergeSort.merge(left, right, arr);
                } else {
                    // For arrays smaller than or equal to the threshold, use normal merge sort
                    MergeSort.mergeSort(arr);
                }
            }
        }
    }

    // public static void main(String[] args) {
    //     // Array sizes to test
    //     int[] testSizes = {1000, 10000, 100000, 1000000, 10000000};
    //     System.out.println("Threshold value : " + THRESHOLD);
    //     // Loop over each test case size
    //     for (int size : testSizes) {

    //         System.out.println("Testing with array size: " + size);
    //         // Initialize arrays with random values
    //         int[] arr1 = new int[size];  // Parallel sort array
    //         int[] arr2 = new int[size];  // Normal sort array

    //         // Fill arrays with random values
    //         for (int i = 0; i < size; i++) {
    //             arr1[i] = arr2[i] = (int)(Math.random() * size);
    //         }

    //         // Benchmark for Parallel Merge Sort
    //         long startTime = System.nanoTime();
    //         parallelMergeSort(arr1);
    //         long endTime = System.nanoTime();
    //         long parallelMergeSortTime = endTime - startTime;
    //         System.out.println("Time taken for parallel merge sort: " + parallelMergeSortTime / 1_000_000 + " ms");

    //         // Benchmark for Normal Merge Sort
    //         startTime = System.nanoTime();
    //         MergeSort.mergeSort(arr2);
    //         endTime = System.nanoTime();
    //         long normalMergeSortTime = endTime - startTime;
    //         System.out.println("Time taken for normal merge sort: " + normalMergeSortTime / 1_000_000 + " ms");

    //         // Calculate percentage speedup or slowdown
    //         if (parallelMergeSortTime < normalMergeSortTime) {
    //             double speedupPercent = ((double)(normalMergeSortTime - parallelMergeSortTime) / normalMergeSortTime) * 100;
    //             System.out.println("Parallel Merge Sort was faster by " + String.format("%.2f", speedupPercent) + "%");
    //         } else {
    //             double slowdownPercent = ((double)(parallelMergeSortTime - normalMergeSortTime) / normalMergeSortTime) * 100;
    //             System.out.println("Parallel Merge Sort was slower by " + String.format("%.2f", slowdownPercent) + "%");
    //         }

    //         System.out.println();  // Empty line between test cases for readability
    //     }
    // }
    public static void main(String[] args) {
        // Array sizes to test
        int[] testSizes = {1000, 10000, 100000, 1000000, 10000000};
        System.out.println("Threshold value : " + THRESHOLD);
    
        // Loop over each test case size
        for (int size : testSizes) {
    
            // Variables to store accumulated times for averaging
            long totalParallelMergeSortTime = 0;
            long totalNormalMergeSortTime = 0;
    
            // Run the test 100 times
            for (int i = 0; i < 1000; i++) {
                // Initialize arrays with random values
                int[] arr1 = new int[size];  // Parallel sort array
                int[] arr2 = new int[size];  // Normal sort array
    
                // Fill arrays with random values
                for (int j = 0; j < size; j++) {
                    arr1[j] = arr2[j] = (int)(Math.random() * size);
                }
    
                // Benchmark for Parallel Merge Sort
                long startTime = System.nanoTime();
                parallelMergeSort(arr1);
                long endTime = System.nanoTime();
                totalParallelMergeSortTime += (endTime - startTime);
    
                // Benchmark for Normal Merge Sort
                startTime = System.nanoTime();
                MergeSort.mergeSort(arr2);
                endTime = System.nanoTime();
                totalNormalMergeSortTime += (endTime - startTime);
            }
    
            // Calculate the average times in milliseconds
            long avgParallelMergeSortTime = totalParallelMergeSortTime / 1000;
            long avgNormalMergeSortTime = totalNormalMergeSortTime / 1000;
    
            // Display the average benchmark results
            System.out.println("Average time taken for parallel merge sort: " + avgParallelMergeSortTime + " ns");
            System.out.println("Average time taken for normal merge sort: " + avgNormalMergeSortTime + " ns");
    
            // Calculate percentage speedup or slowdown
            if (avgParallelMergeSortTime < avgNormalMergeSortTime) {
                double speedupPercent = ((double)(avgNormalMergeSortTime - avgParallelMergeSortTime) / avgNormalMergeSortTime) * 100;
                System.out.println("Parallel Merge Sort was faster by " + String.format("%.2f", speedupPercent) + "%");
            } else {
                double slowdownPercent = ((double)(avgParallelMergeSortTime - avgNormalMergeSortTime) / avgNormalMergeSortTime) * 100;
                System.out.println("Parallel Merge Sort was slower by " + String.format("%.2f", slowdownPercent) + "%");
            }
    
            // Print a message indicating the number of iterations
            System.out.println("Completed 100 iterations for array size " + size + "\n");
        }
    }    
}
