#ifndef HeapSort_h
#define HeapSort_h

#include <iostream>
#include "Heap.h"

using namespace std;

/*
 * 其他的应用：
 * 多路归并，多叉堆，最大最小队列，二项堆，斐波那契堆
 *
 * 优化：
 * 1.ShiftUp和ShiftDown中使用赋值操作替代交换操作
 * 2.表示堆的数组从0开始索引
 * 3.没有capacity的限制，动态的调整堆的大小
 */

template<class T>
void heapSort1(T arr[], int n){
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for(int i = 0; i < n; i++){
		maxheap.insert(arr[i]);
	}
	for(int i = n - 1; i >= 0; i--){
		arr[i] = maxheap.extractMax();
	}
}

template<class T>
void heapSort2(T arr[], int n){
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	for(int i = n - 1; i >= 0; i--){
		arr[i] = maxheap.extractMax();
	}
}

template<class T>
void __shiftDown(T arr[], int n, int k){
	while(2 * k + 1 <= n - 1){
		int j = 2 * k + 1;
		if(j + 1 <= n - 1 && arr[j + 1] > arr[j])
			j += 1;
		if(arr[k] >= arr[j])
			break;
		swap(arr[j], arr[k]);
		k = j;
	}
}

template<class T>
void heapSort(T arr[], int n){
	
	// heapify
	for(int i = (n - 1) / 2; i >= 0; i--){
		__shiftDown(arr, n, i);
	}
	
	for(int i = n - 1; i > 0; i--){
		swap(arr[0], arr[i]);
		__shiftDown(arr, i, 0);
	}
}
#endif
