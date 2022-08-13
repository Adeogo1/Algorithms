//
// Created by adeog on 24/07/2022.
//

#ifndef DATA_BELLMANFORD_H
#define DATA_BELLMANFORD_H
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Edge{
    double cost;
    int from, to;

    Edge(int _from, int _to, double _cost){
        from = _from;
        to = _to;
        cost = _cost;
    }
};
class BellmanFordEdgeList {
    int v;
    vector<Edge*> edges;
public:
    BellmanFordEdgeList(int v){
        this->v = v;

    }

    void AddEdge(int from, int to, double cost){
        if (edges.size() > v)
            return;
        Edge* newEdge = new Edge(from,to, cost);
        edges.push_back(newEdge);
    }

    vector<double> BelmanFord(int start)
    {
        vector<double> dist (v, numeric_limits<double>::infinity());

        dist[start] = 0;
        for (int i = 0; i < v-1; ++i) {
            for (Edge* edge: edges) {
                if (dist[edge->from] + edge->cost < dist[edge->to]){
                    dist[edge->to] = dist[edge->from]+ edge->cost;
                }
            }

        }

        for (int i = 0; i < v-1; ++i) {
            for (Edge* edge: edges) {
                if (dist[edge->from] + edge->cost < dist[edge->to]){
                    dist[edge->to] = numeric_limits<int>::min();
                }
            }

        }
        return dist;
    }
};


#endif //DATA_BELLMANFORD_H
