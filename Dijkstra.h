//
// Created by Tom Guo on 08/11/2017.
//

#ifndef PLAY_WITH_ALGORITHMS_DIJKSTRA_H
#define PLAY_WITH_ALGORITHMS_DIJKSTRA_H

#include <iostream>
#include <vector>
#include <stack>

#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

template <typename Graph, typename Weight>
class Dijkstra {

private:

    Graph &G;
    int s; // 源点

    Weight *disTo; // 从源点到达每个点的最短权值
    bool *marked; // 标记每个点是否找到了最短路径
    vector<Edge<Weight>*> from; // 记录每条最短路径

public:

    Dijkstra(Graph &graph, int s):G(graph) {

        this->s = s;
        disTo = new Weight[G.V()];
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); i++) {
            disTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }

        IndexMinHeap<Weight> ipq(G.V());

        // Dijkstra算法
        disTo[s] = Weight();
        marked[s] = true;
        ipq.insert(s, disTo[s]);
        while (!ipq.isEmpty()) {

            int v = ipq.extractMinIndex();

            marked[v] = true; // disTo[v]就是s到v的最短距离

            // Relaxation
            typename Graph::adjIterator adj(G, v);
            for (auto e = adj.begin(); !adj.end(); e = adj.next()) {
                int w = e->other(v);
                if (!marked[w]) {
                    if (from[w] == NULL || disTo[v] + e->wt() < disTo[w]) {
                        disTo[w] = disTo[v] + e->wt();
                        from[w] = e;
                        if (ipq.contain(w))
                            ipq.change(w, disTo[w]);
                        else
                            ipq.insert(w, disTo[w]);
                    }
                }
            }
        }
    }

    ~Dijkstra() {
        delete[] disTo;
        delete[] marked;
    }

    Weight shortestPathTo(int w) {
        return disTo[w];
    }

    bool hasPathTo(int w) {
        return marked[w];
    }

    void shortestPath(int w, vector<Edge<Weight>>& vec) {

        stack<Edge<Weight>*> s;
        Edge<Weight>* e = from[w];
        while (e->v() != this->s) {
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);
        while (!s.empty()) {
            e = s.top();
            vec.push_back(*e);
            s.pop();
        }
    }

    void showPath(int w) {

        assert(w >= 0 && w < G.V());

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        cout<<vec.size()<<endl;
        for (int i = 0; i < vec.size(); i++) {
            cout<<vec[i].v()<<" -> ";
            if (i == vec.size() - 1)
                cout<<vec[i].w()<<endl;
        }
    }

};

#endif //PLAY_WITH_ALGORITHMS_DIJKSTRA_H
