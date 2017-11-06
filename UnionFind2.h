//
//  UnionFind2.h
//  Algorithm
//
//  Created by Tom Guo on 23/09/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef UnionFind2_h
#define UnionFind2_h

#include <cassert>

using namespace std;

namespace UF2{
	
	class UnionFind{
		
	private:
		
		int* parent;
		int count;
		
	public:
		
		UnionFind(int count){
			parent = new int[count];
			this->count = count;
			for(int i = 0; i < count; i++){
				parent[i] = i;
			}
		}
		~UnionFind(){
			delete[] parent;
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
			parent[pRoot] = qRoot;
		}
		
	};
}
#endif /* UnionFind2_h */
