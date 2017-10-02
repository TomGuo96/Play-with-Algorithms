#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include <iostream>

using namespace std;

// 插入排序
template <typename T>
void insertionSort(T arr[], int n){

	for(int i = 1; i < n; i++){
		// 寻找arr[i]合适的插入位置
		T e = arr[i];
		// 保存e应该插入的位置
		int j;
		for(j = i; j > 0 && arr[j - 1] > e; j--){
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
	return;
}

// 对arr[l-r]氛围内的数组进行插入排序
template <typename T>
void insertionSort(T arr[], int l, int r){
	for(int i = l + 1; i<= r; i++){
		T e = arr[i];
		int j;
		for(j = i; j > l && arr[j - 1] > e; j--){
				arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
	return;
}

#endif
