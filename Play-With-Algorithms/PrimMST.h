//
//  PrimMST.h
//  Algorithm
//
//  Created by Tom Guo on 01/10/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef PrimMST_h
#define PrimMST_h

#include "IndexMinHeap.h"

template<class Graph, class Weight>
class PrimMST{
	
private:
	
	Graph &G;
	IndexMinHeap<Weight> ipq;
	vector<Edge<Weight>*> edgeTo;
	bool* marked;
	vector<Edge<Weight>> mst;
	Weight mstWeight;
	
	void visit(int v){
		
		assert(!marked[v]);
		marked[v] = true;
		
		typename Graph::adjIterator adj(G, v);
		for(Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()){
			
			int w = e->other(v);
			if(!marked[w]){
				if(!edgeTo[w]){
					ipq.insert(w, e->wt());
					edgeTo[w] = e;
				} else if(e->wt() < edgeTo[w]->wt()){
					edgeTo[w] = e;
					ipq.change(w, e->wt());
				}
			}
			
		}
		
	}
	
public:
	
	PrimMST(Graph &graph):G(graph), ipq(IndexMinHeap<double>(graph.V())){
		marked = new bool[G.V()];
		for(int i = 0; i < G.V(); i++){
			marked[i] = false;
			edgeTo.push_back(NULL);
		}
		mst.clear();
		
		// Prim
		visit(0);
		while(!ipq.isEmpty()){
			int v = ipq.extractMinIndex();
			assert(edgeTo[v]);
			mst.push_back(*edgeTo[v]);
			visit(v);
		}
		
		mstWeight = mst[0].wt();
		for(int i = 1; i < mst.size(); i++){
			mstWeight += mst[i].wt();
		}
		
	}
	
	~PrimMST(){
		delete[] marked;
	}
	
	vector<Edge<Weight>> mstEdges(){
		return mst;
	}
	
	Weight result(){
		return mstWeight;
	}
};


#endif /* PrimMST_h */
