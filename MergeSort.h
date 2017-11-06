#ifndef MergeSort_h
#define MergeSort_h

#include <iostream>
#include "InsertionSort.h"

using namespace std;

/*
 *	思考题：
 *	求数组中的逆序对的个数
 */

// 将两部分进行归并
template <class T>
void __merge(T arr[], int l, int mid, int r){
	
	T aux[r - l +1];
	for(int i = l; i <= r; i++){
		aux[i - l] = arr[i];
	}
	
	int i = l, j = mid + 1;
	for(int k = l; k <= r; k++){
		
		if(i > mid){
			arr[k] = aux[j - l];
			j++;
		} else if (j > r) {
			arr[k] = aux[i - l];
			i++;
		} else if (aux[i - l] < aux[j - l]){
			arr[k] = aux[i - l];
			i++;
		} else {
			arr[k] = aux[j - l];
			j++;
		}
		
	}
}

// 递归使用归并排序，对arr[l---r]的范围进行排序
template <class T>
void __mergeSort(T arr[], int l, int r){
//	if (l >= r)
//		return;
	
	if(r - l <= 15){
		insertionSort(arr, l, r);
		return;
	}
	
	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
//	若前半部分最大值小于后半部分的最小值，则无需进行归并
	if(arr[mid] > arr[mid + 1])
		__merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n){
	__mergeSort(arr, 0, n - 1);
}

//自底向上的归并排序
template<class T>
void mergeSortBU(T arr[], int n){
	for(int sz = 1; sz <= n; sz *= 2){
		for(int i = 0; i + sz < n; i += 2 * sz){
			// 对arr[i----i+sz-1]和arr[i+ze---i+2*sz-1]两部分归并
			__merge(arr, i, i + sz -1, min(n - 1,i + 2 * sz -1));
		}
	}
}

#endif
