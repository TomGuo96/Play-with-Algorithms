//
//  UnionFind3.h
//  Algorithm
//
//  Created by Tom Guo on 23/09/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef UnionFind3_h
#define UnionFind3_h

#include <cassert>

using namespace std;

namespace UF3{
	
//	class UnionFind{
//		
//	private:
//		
//		int* parent;
//		int* sz;
//		int count;
//		
//	public:
//		
//		UnionFind(int count){
//			parent = new int[count];
//			sz = new int[count];
//			this->count = count;
//			for(int i = 0; i < count; i++){
//				parent[i] = i;
//				sz[i] = 1;
//			}
//		}
//		~UnionFind(){
//			delete[] parent;
//			delete[] sz;
//		}
//		
//		int find(int p){
//			
//			assert(p >= 0 && p < count);
//			while(p != parent[p]){
//				p = parent[p];
//			}
//			return p;
//			
//		}
//		
//		bool isConnected(int p, int q){
//			return find(p) == find(q);
//		}
//		
//		void unionElements(int p, int q){
//			
//			int pRoot = find(p);
//			int qRoot = find(q);
//			
//			if(pRoot == qRoot){
//				return;
//			}
//			if(sz[pRoot] < sz[qRoot]){
//				parent[pRoot] = qRoot;
//				sz[qRoot] += sz[pRoot];
//			} else {
//				parent[qRoot] = pRoot;
//				sz[pRoot] += sz[qRoot];
//			}
//			
//		}
//		
//	};
	
	class UnionFind{
		
	private:
		
		int* parent;
		int* rank;
		int count;
		
	public:
		
		UnionFind(int count){
			parent = new int[count];
			rank = new int[count];
			this->count = count;
			for(int i = 0; i < count; i++){
				parent[i] = i;
				rank[i] = 1;
			}
		}
		~UnionFind(){
			delete[] parent;
			delete[] rank;
		}
		
		int find(int p){
			
			assert(p >= 0 && p < count);
			while(p != parent[p]){
				p = parent[p];
			}
			return p;
			
		}
		
		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
		
		void unionElements(int p, int q){
			
			int pRoot = find(p);
			int qRoot = find(q);
			
			if(pRoot == qRoot){
				return;
			}
			if(rank[pRoot] < rank[qRoot]){
				parent[pRoot] = qRoot;
			} else if(rank[qRoot] < rank[pRoot]){
				parent[qRoot] = pRoot;
			} else {
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;
			}
			
		}
		
	};
}


#endif /* UnionFind3_h */
