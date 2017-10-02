//
//  ReadGraph.h
//  Algorithm
//
//  Created by Tom Guo on 24/09/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef ReadGraph_h
#define ReadGraph_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

//template <class Graph>
//class ReadGraph{
//
//public:
//	
//	ReadGraph(Graph &graph, const string &filename){
//		
//		ifstream file(filename);
//		string line;
//		int V, E;
//		
//		assert(file.is_open());
//		assert(getline(file, line));
//		stringstream ss(line);
//		ss>>V>>E;
//		
//		assert(V == graph.V());
//		
//		for(int i = 0; i < E; i++){
//			
//			assert(getline(file, line));
//			stringstream ss(line);
//			
//			int a, b;
//			ss>>a>>b;
//			
//			assert(a >= 0 && a < V);
//			assert(b >= 0 && b < V);
//			graph.addEdge(a, b);
//		}
//	}
//	
//};

// 读取带权信息
template <class Graph, class Weight>
class ReadGraph{
	
public:
	
	ReadGraph(Graph &graph, const string &filename){
		
		ifstream file(filename);
		string line;
		int V, E;
		
		assert(file.is_open());
		assert(getline(file, line));
		stringstream ss(line);
		ss>>V>>E;
		
		assert(V == graph.V());
		
		for(int i = 0; i < E; i++){
			
			assert(getline(file, line));
			stringstream ss(line);
			
			int a, b;
			Weight w;
			ss>>a>>b>>w;
			
			assert(a >= 0 && a < V);
			assert(b >= 0 && b < V);
			graph.addEdge(a, b, w);
		}
	}
	
};

#endif /* ReadGraph_h */
