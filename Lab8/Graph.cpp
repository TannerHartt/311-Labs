// CSCI 311 
// Graph class cpp
// Author:

#include <iostream>
#include "Graph.h"
#include <queue>
#include <limits.h>
using namespace std;

//do not change the header files
//implement the following functions and do not introduce new functions

Graph::Graph(){
}

void Graph::printAdjList(){
}

bool Graph::isNeighbor(int u, int v){
  return false;
}

void Graph::DFS(){
}

int Graph::DFSVisit(int s, int time){
  return time;
}

void Graph::BFS(int s){
}

std::vector<int> Graph::distancesFrom(int s){
}

bool Graph::isTwoColorable(){
  for (auto& node : nodes) { // 'Reset' all nodes
    node->visited = false;
    node->color = "";
  }

  for (auto node : nodes) {
    if (!node->visited) {
      node->color = "red";
      node->visited = true;
      queue<shared_ptr<Node>> q;
      q.push(node);

      while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        // Check all adjacent nodes
        for (auto &n : curr->neighbors) {
          if (!n->visited) {
            // Color the neighbor with the opposite color
            n->color = (curr->color == "red") ? "blue" : "red";
            n->visited = true;
            n->predecessor = curr;
            q.push(n);
          }
          else if (n->visited && n->color == curr->color) {
            return false;
          }
        }
      }
    }
  }
  return true; // default case
}

bool Graph::isConnected(){
  if (nodes.empty()) return true;

  queue<shared_ptr<Node>> q;
  vector<bool> visited(nodes.size(), false);

  visited[0] = true;
  q.push(nodes[0]);
  int count = 0;

  while (!q.empty()) {
    auto node = q.front();
    q.pop();

    for (auto &neighbor : node->neighbors) {
      int neighborId = neighbor->id;
      if (!visited[neighborId]) {
        visited[neighborId] = true;
        q.push(neighbor);
      }
    }
  }
  for (bool v : visited) {
        if (!v) return false; // If any node was not visited, the graph is not connected
    }
    return true;
}

bool Graph::hasCycle(){
  vector<bool> visited(nodes.size(), false);
  for (int i = 0; i < nodes.size(); i++) {
    if (!visited[i] && hasCycleRecur(i)) {
      return true;
    }
  }
  return false;
}

bool Graph::hasCycleRecur(int s){
  nodes[s]->visited = true;

  for (auto& neighbor : nodes[s]->neighbors) {
      if (!neighbor->visited) {
          neighbor->predecessor = nodes[s];
          if (hasCycleRecur(neighbor->id)) {
              return true;
          }
      } else if (neighbor->id != nodes[s]->predecessor->id) {
          return true;
      }
  }
    return false;
}

bool Graph::isReachable(int u, int v){
  if (u >= nodes.size() || v >= nodes.size()) return false; // Check if u or v are out of bounds
    if (u == v) return true; // A node is always reachable from itself - step 1 from class example

    vector<bool> visited(nodes.size(), false); // To track visited nodes
    queue<int> q;
    visited[u] = true;
    q.push(u);

    while (!q.empty()) {
      int current = q.front();
      q.pop();

      for (auto& neighbor : nodes[current]->neighbors) {
        int neighborId = neighbor->id;

        if (neighborId == v) {
            return true; // Node v reached
        }

        if (!visited[neighborId]) {
            visited[neighborId] = true;
            q.push(neighborId);
        }
      }
    }
    return false; // Not reachable, defaut case
}