#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Edge {
    public:
        int id1, id2;
        int weight;

        Edge() {}
        Edge(int id1, int id2, int weight) : id1(id1), id2(id2), weight(weight) {}
};
