//
//  LazyPrimMST.h
//  Algorithm
//
//  Created by Tom Guo on 27/09/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef LazyPrimMST_h
#define LazyPrimMST_h

#include "MinHeap.h"
#include "Edge.h"

using namespace std;

template <class Graph, class Weight>
class LazyPrimMST{
	
private:
	
	Graph &G;
	bool *marked;
	MinHeap<Edge<Weight>> pq;
	vector<Edge<Weight>> mst;
	Weight mstWeight;
	
	void visit(int v){
		assert(!marked[v]);
		marked[v] = true;
		
		typename Graph::adjIterator adj(G, v);
		for(Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next()){
			if(!marked[e->other(v)]){
				pq.insert(*e);
			}
		}
	}
	
public:
	
	LazyPrimMST(Graph &graph):G(graph), pq(MinHeap<Edge<Weight>>(graph.E())){
		marked = new bool[G.V()];
		for(int i = 0; i < G.V(); i++){
			marked[i] = false;
		}
		mst.clear();
		
		// Lazy Prime
		visit(0);
		while(!pq.isEmpty()){
			Edge<Weight> e = pq.extractMin();
			if(marked[e.v()] == marked[e.w()]){
				continue;
			}
			mst.push_back(e);
			if(!marked[e.v()]){
				visit(e.v());
			} else {
				visit(e.w());
			}
		}
		
		mstWeight = mst[0].wt();
		for(int i = 1; i < mst.size(); i++){
			mstWeight += mst[i].wt();
		}
	}
	
	~LazyPrimMST(){
		delete[] marked;
	}
	
	vector<Edge<Weight>> mstEdges(){
		return mst;
	}
	Weight result(){
		return mstWeight;
	}
};


#endif /* LazyPrimMST_h */
