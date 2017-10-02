#ifndef Heap_h
#define Heap_h

#include <iostream>

using namespace std;

template<typename Item>
class MaxHeap{

private:
	
	Item* data;
	int count;
	int capacity;

	void shiftUp(int k){
		while( k > 1 && data[k / 2] < data[k]){
			swap(data[k / 2], data[k]);
			k /= 2;
		}
	}
	
	void shiftDown(int k){
		while(2 * k <= count){
			int j = 2 * k;
			if(j + 1 <= count && data[j + 1] > data[j])
				j += 1;
			if(data[k] >= data[j])
				break;
			swap(data[j], data[k]);
			k = j;
		}
	}

public:
	
	MaxHeap(int capacity){
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	MaxHeap(Item arr[], int n){
		data = new Item[n + 1];
		capacity = n;
		for(int i = 0; i < n; i++){
			data[i + 1] = arr[i];
		}
		count = n;
		for(int i = count / 2; i >= 1; i--){
			shiftDown(i);
		}
	}
	~MaxHeap(){
		delete[] data;
	}
	
	int getSize(){
		return count;
	}
	int getCapacity(){
		return capacity;
	}
	bool isEmpty(){
		return count == 0;
	}

//	插入新数据
	void insert(Item item){
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		count++;
		shiftUp(count);
	}

//	取出最大值
	Item extractMax(){
		
		assert(count > 0);
		
		Item ret = data[1];
		
		swap(data[1], data[count]);
		count--;
		shiftDown(1);
		
		return ret;
		
	}
//	打印数据
	void printItems(){
		cout<<"该最大堆共有"<<count<<"个数据"<<endl;
		for (int i = 1; i <= count; i++){
			cout<<data[i]<<" ";
			if(i % 20 == 0){
				cout<<endl;
			}
		}
		cout<<endl;
		return;
	}

};

template<typename Item>
class IndexMaxHeap{
	
private:
	
	Item* data;
	Item* indexs;
	Item* reverse;
	
	int count;
	int capacity;
	
	void shiftUp(int k){
		while( k > 1 && data[indexs[k / 2]] < data[indexs[k]]){
			swap(indexs[k / 2], indexs[k]);
			reverse[indexs[k / 2]] = k / 2;
			reverse[indexs[k]] = k;
			k /= 2;
		}
	}
	
	void shiftDown(int k){
		while(2 * k <= count){
			int j = 2 * k;
			if(j + 1 <= count && data[indexs[j + 1]] > data[indexs[j]])
				j += 1;
			if(data[indexs[k]] >= data[indexs[j]])
				break;
			swap(indexs[j], indexs[k]);
			reverse[indexs[j]] = j;
			reverse[indexs[k]] = k;
			k = j;
		}
	}
	
public:
	
	IndexMaxHeap(int capacity){
		data = new Item[capacity + 1];
		indexs = new int[capacity + 1];
		for(int i = 0; i < capacity; i++){
			reverse[i] = 0;
		}
		count = 0;
		this->capacity = capacity;
			}
	IndexMaxHeap(Item arr[], int n){
		data = new Item[n + 1];
//		indexs = new int[capacity + 1];
		capacity = n;
		for(int i = 0; i < n; i++){
			data[i + 1] = arr[i];
		}
		count = n;
		for(int i = count / 2; i >= 1; i--){
			shiftDown(i);
		}
	}
	~IndexMaxHeap(){
		delete[] data;
		delete[] indexs;
		delete[] reverse;
	}
	
	int getSize(){
		return count;
	}
	int getCapacity(){
		return capacity;
	}
	bool isEmpty(){
		return count == 0;
	}
	
	//	插入新数据
	// 对用户而言i从0开始
	void insert(int i, Item item){
		
		assert(count + 1 <= capacity);
		assert(i >= 0 && i + 1 <= capacity);
		
		i += 1;
		data[i] = item;
		indexs[count + 1] = i;
		reverse[i] = count + 1;
		count++;
		shiftUp(count);
	}
	
	//	取出最大值
	Item extractMax(){
		
		assert(count > 0);
		
		Item ret = data[indexs[1]];
		
		swap(indexs[1], indexs[count]);
		reverse[indexs[1]] = 1;
		reverse[indexs[count]] = 0;
		count--;
		shiftDown(1);
		
		return ret;
		
	}
	
	int extractMaxIndex(){
		assert(count > 0);
		int ret = indexs[1] - 1;
		swap(indexs[1], indexs[count]);
		reverse[indexs[1]] = 1;
		reverse[indexs[count]] = 0;
		count--;
		shiftDown(1);
		
		return ret;
	}
	
	bool contain(int i){
		assert(i + 1 >= 1 && i + 1 <= capacity);
		return reverse[i + 1] != 0;
	}
	
	Item getItem(int i){
		
		assert(contain(i));
		return data[i + 1];
	}
	
	void change(int i, Item newItem){
		
		assert(contain(i));
		i += 1;
		data[i] = newItem;
		
	// 找到indexs[j]=i，j表示data[j]在堆中的位置，之后shiftUp(j),再shiftDown(j)
//		for(int j = 1; j <= count; j++){
//			if(indexs[j] == i){
//				shiftUp(j);
//				shiftDown(j);
//				
//				return;
//			}
//		}
		int j = reverse[i];
		shiftDown(j);
		shiftUp(j);
	}
	//	打印用户视角的数据
	void printUserItems(){
		cout<<"共有"<<count<<"个数据，该最大堆的用户数组如下："<<count<<"个数据"<<endl;
		for (int i = 1; i <= count; i++){
			cout<<data[i]<<" ";
			if(i % 20 == 0){
				cout<<endl;
			}
		}
		cout<<endl;
		return;
	}
	
	// 打印实际最大堆的数据
	void printItems(){
		cout<<"共有"<<count<<"个数据，该最大堆的排序数组如下："<<endl;
		for (int i = 1; i <= count; i++){
			cout<<data[indexs[i]]<<" ";
			if(i % 20 == 0){
				cout<<endl;
			}
		}
		if(count % 20 != 0){
			cout<<endl;
		}
		return;
	}
	
	// 打印索引数组
	void printIndex(){
		cout<<"共有"<<count<<"个数据，该最大堆的索如下："<<endl;
		for(int i = 0; i < count; i++){
			cout<<indexs[i]<<" ";
			if(i % 20 == 0){
				cout<<endl;
			}
		}
		cout<<endl;
	}
	
};

#endif
