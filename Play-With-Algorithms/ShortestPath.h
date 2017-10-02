//
//  ShortestPath.h
//  Algorithm
//
//  Created by Tom Guo on 24/09/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef ShortestPath_h
#define ShortestPath_h

#include <cassert>
#include <queue>

template <class Graph>
class ShortestPath{
	
private:
	
	Graph &G;
	int s;
	bool *visited;
	int *from;
	int *ord;
	
public:
	
	ShortestPath(Graph &graph, int s):G(graph){
		
		//算法初始化
		assert(s >= 0 && s < G.V());
		
		visited = new bool[G.V()];
		from = new int[G.V()];
		ord = new int[G.V()];
		for(int i = 0; i < G.V(); i++){
			visited[i] = false;
			from[i] = -1;
			ord[i] = -1;
		}
		this->s = s;
		
		queue<int> q;
		
		// 无向图最短路径算法
		q.push(s);
		visited[s] = true;
		ord[s] = 0;
		
		while(!q.empty()){
			
			int v = q.front();
			q.pop();
			typename Graph::adjIterator adj(G, v);
			for(int i = adj.begin(); !adj.end(); i = adj.next()){
				if(!visited[i]){
					q.push(i);
					visited[i] = true;
					from[i] = v;
					ord[i] = ord[v] + 1;
				}
			}
		}
		
	}
	~ShortestPath(){
		delete[] visited;
		delete[] from;
		delete[] ord;
	}
	
	bool hasPath(int w){
		assert(w >= 0 && w < G.V());
		return visited[w];
	}
	
	void path(int w, vector<int> &vec){
		assert(w >= 0 && w < G.V());
		stack<int> s;
		int p = w;
		while(p != -1){
			s.push(p);
			p = from[p];
		}
		vec.clear();
		while(!s.empty()){
			vec.push_back(s.top());
			s.pop();
		}
	}
	
	void showPath(int w){
		assert(w >= 0 && w < G.V());
		vector<int> vec;
		path(w, vec);
		for(int i = 0; i < vec.size(); i++){
			cout<<vec[i];
			if(i == vec.size() - 1)
				cout<<endl;
			else
				cout<<" -> ";
		}
	}
	
	int length(int w){
		assert(w >= 0 && w <G.V());
		return ord[w];
	}
	
};

#endif /* ShortestPath_h */
