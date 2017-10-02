#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper{
    
    // 生成n个元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
    int* generateRandomArray(int n, int rangeL, int rangeR){
        
        assert(rangeL <= rangeR);
        
        int *arr = new int[n];
        srand((unsigned)time(NULL));
        for(int i = 0; i < n; i++){
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }
    
    // 生成近乎有序的随机数组
    int* generateNearlyOrderedArray(int n, int swapTimes){
        int* arr = new int[n];
        for (int i = 0; i < n; i++){
            arr[i] = i;
        }
        srand((unsigned)time(NULL));
        for(int i = 0; i < swapTimes; i++){
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }
    
    // 拷贝整型数组
    int* copyIntArray(int a[], int n){
        int* arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }
    
    // 检查数组是否有序
    template<typename T>
    bool isSorted(T arr[], int n){
			for(int i = 0; i < n - 1; i++){
				if(arr[i] > arr[i + 1])
					return false;
			}
			return true;
    }
    
    // 测试排序算法的时间效率
    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n){
        
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        
        assert(isSorted(arr, n));
        cout<<sortName<<": "<<double(endTime - startTime) / CLOCKS_PER_SEC<<" s."<<endl;
        
        return;
    }
    
    // 打印数组
    template<typename T>
    void printArray(T arr[], int n){
        for (int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

#endif
