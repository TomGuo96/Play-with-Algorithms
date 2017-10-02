//
//  Edge.h
//  Algorithm
//
//  Created by Tom Guo on 25/09/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef Edge_h
#define Edge_h

#include <iostream>

template <class Weight>
class Edge{
	
private:
	
	int a, b;
	Weight weight;
	
public:
	
	Edge(int a, int b, Weight weight){
		this->a = a;
		this->b = b;
		this->weight = weight;
	}
	
	Edge(){};
	~Edge(){};
	
	int v(){ return a;}
	int w(){ return b;}
	
	Weight wt(){ return weight;}
	
	int other(int x){
		assert(x == a || x == b);
		return x == a ? b : a;
	}
	
	friend ostream& operator<<(ostream &os, const Edge &e){
		os<<e.a<<"-"<<e.b<<":"<<e.weight;
		return os;
	}
	
	bool operator<(Edge<Weight>& e){
		return weight < e.wt();
	}
	bool operator>(Edge<Weight>& e){
		return weight > e.wt();
	}
	bool operator<=(Edge<Weight>& e){
		return weight <= e.wt();
	}
	bool operator>=(Edge<Weight>& e){
		return weight >= e.wt();
	}
	bool operator==(Edge<Weight>& e){
		return weight == e.wt();
	}
};

#endif /* Edge_h */
