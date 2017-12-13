//
// Created by Tom Guo on 09/11/2017.
//

#ifndef PLAY_WITH_ALGORITHMS_BELLMANFORD_H
#define PLAY_WITH_ALGORITHMS_BELLMANFORD_H

#include <vector>
#include <stack>

#include "Edge.h"

using namespace std;

template <typename Graph, typename Weight>
class BellmanFord {

private:

    Graph &G;
    int s;
    Weight* disTo;
    vector<Edge<Weight>*> from;
    bool hasNegativeCycle;

    bool detectNegativeCycle() {
        for (int i = 0; i < G.V(); i++) {
            typename Graph::adjIterator adj(G, i);
            for (auto e = adj.begin(); !adj.end(); e = adj.next()) {
                if (disTo[e->v()] + e->wt() < disTo[e->w()] || !from[e->w()]) {
                    return true;
                }
            }
        }
        return false;
    }

public:

    BellmanFord(Graph &graph, int s):G(graph) {
        this->s = s;
        disTo = new Weight[G.V()];
        for (int i = 0; i < G.V(); i++) {
            from.push_back(NULL);
        }

        // Bellman-Ford算法
        disTo[s] = Weight();
        for (int pass = 1; pass < G.V(); pass++) {
            // Relaxation
            for (int i = 0; i < G.V(); i++) {
                typename Graph::adjIterator adj(G, i);
                for (auto e = adj.begin(); !adj.end(); e = adj.next()) {
                    if (disTo[e->v()] + e->wt() < disTo[e->w()] || !from[e->w()]) {
                        disTo[e->w()] = disTo[e->v()] + e->wt();
                        from[e->w()] = e;
                    }
                }
            }
        }
        hasNegativeCycle = detectNegativeCycle();
    }

    ~BellmanFord() {
        delete[] disTo;
    }

    bool negativeCycle() {
        return hasNegativeCycle;
    }

    bool hasPathTo(int w) {
        assert(w >= 0 && w < G.V());
        return from[w] != NULL;
    }

    Weight shortestPathTo(int w) {
        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);
        return disTo[w];
    }

    Weight shortestPath(int w, vector<Edge<Weight>>& vec) {

        assert(w >= 0 && w < G.V());
        assert(!hasNegativeCycle);

        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
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
        assert(!hasNegativeCycle);

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for (int i = 0; i < vec.size(); i++) {
            cout<<vec[i].v()<<" -> ";
            if (i == vec.size() - 1)
                cout<<vec[i].w()<<endl;
        }
    }
};

#endif //PLAY_WITH_ALGORITHMS_BELLMANFORD_H
