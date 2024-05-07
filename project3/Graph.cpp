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

class Node {
    public: 
        int id;
        bool hasCharger;
        int dist;
        int RC;
        vector<int> path;

        Node() {}
        Node(int id, bool hasCharger) : id(id), hasCharger(hasCharger), dist(INT_MAX), RC(0) {}

        void setStartParameters(int distance, int remainingCharge) {
            dist = distance;
            RC = remainingCharge;
        }
};

class Graph {
    public:
        vector<Node> nodes;
        vector<Edge> edges;

        Graph(int numberOfNodes) {
            nodes.reserve(numberOfNodes);
            for (int i = 0; i < numberOfNodes; i++) {
                nodes.emplace_back(Node(i, false));
            }
        }

        void addNode(int id, bool hasCharger) {
            nodes[id] = Node(id, hasCharger);
        }

        void addEdge(int id1, int id2, int weight) {
            edges.push_back(Edge(id1, id2, weight));
        }

        Node& getNode(int id) {
            return nodes[id];
        }

        void verifyPath(const vector<int>& path) {
            cout << "Verify Path: ";
            for (int id : path) {
                cout << id << " ";
            }
            cout << endl;
        }
};