//
//  BinarySearch.h
//  Algorithm
//
//  Created by Tom Guo on 23/09/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef BinarySearch_h
#define BinarySearch_h

#include <iostream>

using namespace std;

//数组已经有序
template<class T>
int binarySearch(T arr[], int n, T target){
	
	int l = 0, r = n - 1;
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(arr[mid] == target){
			return mid;
		} else if(target < arr[mid]){
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	
	return -1;
}
#endif /* BinarySearch_h */
