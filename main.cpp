#include <iostream>
#include <iomanip>

#include "ReadGraph.h"
#include "Dijkstra.h"
#include "BellmanFord.h"

using namespace std;

int main(){

	string filename = "/Users/tom/Documents/Code/Play-with-Algorithms/testG.txt";
	int V = 5;

	SparseGraph<int> g = SparseGraph<int>(V, true);
	ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

	cout<<"Test BellmanFord: "<<endl<<endl;
	BellmanFord<SparseGraph<int>, int> bellmanFord(g, 0);
	if (bellmanFord.negativeCycle()) {
		cout<<"The graph conatain negative cycle!"<<endl;
	} else {
		for (int i = 1; i < V; i++) {
			cout<<"Shortest Path to "<<i<<" : "<<bellmanFord.shortestPathTo(i)<<endl;
			bellmanFord.showPath(i);
			cout<<"----------"<<endl;
		}
	}

	return 0;
}

