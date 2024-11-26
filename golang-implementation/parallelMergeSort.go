package main

import "sort"

const threshold = 5000

func parallelMergeSort(arr []int, c chan []int) {
	if len(arr) <= 1 {
		c <- arr
		return
	}

	if len(arr) <= threshold {
		sort.Slice(arr, func(i, j int) bool { return arr[i] < arr[j] })
		c <- arr
		return
	}

	mid := len(arr) / 2
	leftChan := make(chan []int)
	rightChan := make(chan []int)

	go parallelMergeSort(arr[:mid], leftChan)
	go parallelMergeSort(arr[mid:], rightChan)

	left := <-leftChan
	right := <-rightChan

	c <- merge(left, right)
}
