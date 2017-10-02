//
//  UnionFind4.h
//  Algorithm
//
//  Created by Tom Guo on 23/09/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef UnionFind4_h
#define UnionFind4_h

#include <cassert>

using namespace std;

namespace UF4{
	
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
		
//		int find(int p){
//			
//			assert(p >= 0 && p < count);
//			while(p != parent[p]){
//				// 路径压缩
//				parent[p] = parent[parent[p]];
//				p = parent[p];
//			}
//			return p;
//			
//		}
		
		/*
		 * 第二个版本的路径压缩
		 * 理论更优，实际略差
		 */
		
		int find(int p){

			assert(p >= 0 && p < count);
			
			if(p != parent[p]){
				parent[p] = find(parent[p]);
			}
			return parent[p];
			
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


#endif /* UnionFind4_h */
