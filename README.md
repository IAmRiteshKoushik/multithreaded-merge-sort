# Implementing Multithreaded Merge Sort

Usually, when we think of sorting algorithms, we operate with O(nlogn) time 
complexity as the first sorting methods come to mind are **Quick Sort** and 
**Merge Sort**. Both of these take a recursive approach towards handling things. 

**Thought** : Can we mix recursion with multithreading and make things faster ?

**Preliminary Idea**
1. As merge sort takes a divide and conquer approach, the sub-arrays which 
are to be further sorted individually during the divide step are not a shared 
resource.
2. Here, we can offload the execution to different threads without the 
requirement of any form of Mutex lock.
3. One problem that can arise is the resource constraint of the host machine 
one which this algorithm is being executed. We might run out of threads that 
the OS can offer if we are to carry out the algorithm for a huge array.
4. A potential solution to this is maintaining a [thread pool](https://www.youtube.com/watch?v=NgYS6mIUYmA&pp=ygULdGhyZWFkIHBvb2w%3D) of say 1000 threads.
5. If our thread pool is exhausted then we will not spin up more threads but fall 
back to recursion.

> [!NOTE]
> Implemented thread pools in Go to understand their working. Check [here](./thread-pool/main.go)

**Aim of Experiment**
Explore Merge Sort of 10 to the power 7 elements through merge-sort in 
non-parallel and parallel environments. 


