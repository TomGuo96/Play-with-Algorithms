//
//  Component.h
//  Algorithm
//
//  Created by Tom Guo on 24/09/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef Component_h
#define Component_h

#include <iostream>
#include <cassert>
using namespace std;

template <class Graph>
class Component{
	
private:
	
	Graph &G;
	bool *visited;
	int ccount;
	int *id;
	
	void dfs(int v){
		
		id[v] = ccount;
		visited[v] = true;
		typename Graph::adjIterator adj(G, v);
		for(int i = adj.begin(); !adj.end(); i = adj.next()){
			if(!visited[i])
				dfs(i);
		}
	}
	
public:
	
	Component(Graph &graph):G(graph){
		
		visited = new bool[G.V()];
		id = new int[G.V()];
		ccount = 0;
		for(int i = 0; i < G.V(); i++){
			visited[i] = false;
			id[i] = -1;
		}
		for(int i = 0; i < G.V(); i++){
			if(!visited[i]){
				dfs(i);
				ccount++;
			}
		}
	}
	~Component(){
		delete[] visited;
		delete[] id;
	}
	int count(){
		return ccount;
	}
	
	bool isConnected(int v, int w){
		assert(v >= 0 && v < G.V());
		assert(w >= 0 && v < G.V());
		return id[v] == id[w];
	}
};

#endif /* Component_h */
