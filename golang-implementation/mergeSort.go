package main


func mergeSort(arr []int) []int {
	if len(arr) <= 1 {
		return arr
	}

	mid := len(arr) / 2
	left := mergeSort(arr[:mid])
	right := mergeSort(arr[mid:])

	return merge(left, right)
}

func merge(left, right []int) []int {
	result := make([]int, len(left)+len(right))
	l, r := 0, 0
	for i := 0; i < len(result); i++ {
		if l >= len(left) {
			result[i] = right[r]
			r++
			continue
		}
		if r >= len(right) {
			result[i] = left[l]
			l++
			continue
		}
		if left[l] < right[r] {
			result[i] = left[l]
			l++
		} else {
			result[i] = right[r]
			r++
		}
	}
	return result
}
