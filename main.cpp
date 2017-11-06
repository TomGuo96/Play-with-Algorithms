#include <iostream>
#include <iomanip>
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ShortestPath.h"
#include "LazyPrimMST.h"
#include "PrimMST.h"
#include "KruskalMST.h"

using namespace std;

int main(){
	
	string filename = "/Users/tom/Documents/Programming/Play-With-Algorithms/Play-With-Algorithms/testG3.txt";
	int V = 8;
	
	SparseGraph<double> g = SparseGraph<double>(V, false);
	ReadGraph<SparseGraph<double>, double> readGraph(g, filename);
	
	cout<<"Test Lazy Prim MST:"<<endl;
	LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
	vector<Edge<double>> mst = lazyPrimMST.mstEdges();
	for(int i = 0; i < mst.size(); i++){
		cout<<mst[i]<<endl;
	}
	cout<<"The MST weight is: "<<lazyPrimMST.result()<<endl;
	cout<<endl;
	
	cout<<"Test Prim MST:"<<endl;
	PrimMST<SparseGraph<double>, double> primMST(g);
	mst = primMST.mstEdges();
	for(int i = 0; i < mst.size(); i++){
		cout<<mst[i]<<endl;
	}
	cout<<"The MST weight is: "<<primMST.result()<<endl;
	cout<<endl;
	
	cout<<"Test Kruskal MST:"<<endl;
	KruskalMST<SparseGraph<double>, double> kruskalMST(g);
	mst = kruskalMST.mstEdges();
	for(int i = 0; i < mst.size(); i++){
		cout<<mst[i]<<endl;
	}
	cout<<"The MST weight is: "<<kruskalMST.reuslt()<<endl;
	
	return 0;
}

