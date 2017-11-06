//
//  UnionFindTestHelper.h
//  Algorithm
//
//  Created by Tom Guo on 23/09/2017.
//  Copyright © 2017 Tom Guo. All rights reserved.
//

#ifndef UnionFindTestHelper_h
#define UnionFindTestHelper_h

#include <iostream>
#include <ctime>
#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"

using namespace std;

namespace UnionFindTestHelper{
	
	void testUF1(int n){
		
		srand((unsigned)time(NULL));
		UF1::UnionFind uf = UF1::UnionFind(n);
		
		clock_t startTime = clock();
		
		for(int i = 0; i < n; i++){
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		
		clock_t endTime = clock();
		
		std::cout<<"UF1, "<<2 * n<<" ops, "<<double(endTime - startTime) / CLOCKS_PER_SEC<<" s."<<endl;
	}
	
	void testUF2(int n){
		
		srand((unsigned)time(NULL));
		UF2::UnionFind uf = UF2::UnionFind(n);
		
		clock_t startTime = clock();
		
		for(int i = 0; i < n; i++){
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		
		clock_t endTime = clock();
		
		std::cout<<"UF2, "<<2 * n<<" ops, "<<double(endTime - startTime) / CLOCKS_PER_SEC<<" s."<<endl;
	}
	
	void testUF3(int n){
		
		srand((unsigned)time(NULL));
		UF3::UnionFind uf = UF3::UnionFind(n);
		
		clock_t startTime = clock();
		
		for(int i = 0; i < n; i++){
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		
		clock_t endTime = clock();
		
		std::cout<<"UF3, "<<2 * n<<" ops, "<<double(endTime - startTime) / CLOCKS_PER_SEC<<" s."<<endl;
	}

	void testUF4(int n){
		
		srand((unsigned)time(NULL));
		UF4::UnionFind uf = UF4::UnionFind(n);
		
		clock_t startTime = clock();
		
		for(int i = 0; i < n; i++){
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		
		clock_t endTime = clock();
		
		std::cout<<"UF4, "<<2 * n<<" ops, "<<double(endTime - startTime) / CLOCKS_PER_SEC<<" s."<<endl;
	}

}

#endif /* UnionFindTestHelper_h */
