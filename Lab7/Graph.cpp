// CSCI 311 lab 7

#include <iostream>
#include "Graph.h"
#include <queue>
#include <limits>
using namespace std;

Graph::Graph(){
  nodes = {};
}

void Graph::printAdjList(){
  for (int i = 0; i < nodes.size(); i++) {
    auto node = nodes[i];
    cout << node->id << ": ";
    for (auto &neighbor : node->neighbors) {
        cout << neighbor->id << " ";
    }
    cout << endl;
  }
}

bool Graph::isNeighbor(int u, int v){
  for (auto &neighbor : nodes[u]->neighbors) {
    if (neighbor->id == v) {
        return true;
    }
  }
  return false;
}

void Graph::DFS(){
  int time = 0;
  // Reset all nodes as unvisited
  for (auto &n : nodes) {
      n->visited = false;
      n->predecessor = nullptr;
  }
  // Visit each node if not already visited
  for (auto &n : nodes) {
    if (!n->visited) {
        time = DFSVisit(n->id, time);
    }
  }
}

int Graph::DFSVisit(int s, int time){
  nodes[s]->visited = true;
  nodes[s]->discovered = ++time;
  for (auto &neighbor : nodes[s]->neighbors) {
      if (!neighbor->visited) {
          neighbor->predecessor = nodes[s];
          time = DFSVisit(neighbor->id, time);
      }
  }
  nodes[s]->finished = ++time;
  return time;
}

void Graph::BFS(int s){
  auto list = nodes[s];
  queue<shared_ptr<Node>> q;
  // Reset all nodes
  for (auto &node : nodes) {
    node->visited = false;
    node->predecessor = nullptr;
    node->dist = numeric_limits<int>::max();
  }
    
  list->dist = 0;
  list->visited = true;
  q.push(list);

  while (!q.empty()) {
    auto current = q.front();
    q.pop();

    for (auto &neighbor : current->neighbors) {
      if (!neighbor->visited) {
        neighbor->visited = true;
        neighbor->dist = current->dist + 1;
        neighbor->predecessor = current;
        q.push(neighbor);
      }
    }
  }
}

vector<int> Graph::distancesFrom(int s){
  BFS(s);
  vector<int> distances;
  for (auto &node : nodes) {
      distances.push_back(node->dist);
  }
  return distances;
}
