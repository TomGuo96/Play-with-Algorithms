//
//  KruskalMST.h
//  Algorithm
//
//  Created by Tom Guo on 01/10/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef KruskalMST_h
#define KruskalMST_h

#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "UnionFind4.h"
#include "Edge.h"

using namespace std;

template <class Graph, class Weight>
class KruskalMST{
	
	
private:
	
	vector<Edge<Weight>> mst;
	Weight mstWeight;
	
public:
	
	KruskalMST(Graph &graph){
		
		MinHeap<Edge<Weight>> pq(graph.E());
		for(int i = 0; i < graph.V(); i++){
			typename Graph::adjIterator adj(graph, i);
			for(Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()){
				if(e->v() < e->w()){
					pq.insert(*e);
				}
			}
		}
		
		UF4::UnionFind uf(graph.V());
		while(!pq.isEmpty() && mst.size() < graph.V() - 1){
			Edge<Weight> e = pq.extractMin();
			if(uf.isConnected(e.v(), e.w()))
				continue;
			mst.push_back(e);
			uf.unionElements(e.v(), e.w());
		}
		
		mstWeight = mst[0].wt();
		for(int i = 1; i < mst.size(); i++){
			mstWeight += mst[i].wt();
		}
		
	}
	~KruskalMST(){
		
	}
	
	vector<Edge<Weight>> mstEdges(){
		return mst;
	}
	Weight reuslt(){
		return mstWeight;
	}
};

#endif /* KruskalMST_h */
