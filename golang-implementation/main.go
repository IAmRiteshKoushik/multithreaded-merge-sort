package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	arraySizes := []int{1000, 10000, 100000, 1000000, 10000000}

	for _, size := range arraySizes {
		arr1 := []int{}

		for i := 0; i < size; i++ {
			arr1 = append(arr1, rand.Intn(size))
		}

		// Timing normal merge sort
		startMergeSort := time.Now()
		mergeSort(arr1)
		elapsedMergeSort := time.Since(startMergeSort)
		fmt.Println("MergeSort for", size, "elements took", elapsedMergeSort)

		// Timing parallel merge sort
		arr2 := make([]int, len(arr1))
		copy(arr2, arr1)
		startParallelMergeSort := time.Now()
		ch := make(chan []int)
		go parallelMergeSort(arr2, ch)
		<-ch
		elapsedParallelMergeSort := time.Since(startParallelMergeSort)
		fmt.Println("ParallelMergeSort for", size, "elements took", elapsedParallelMergeSort)

	}
}
