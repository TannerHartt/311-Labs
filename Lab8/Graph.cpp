// CSCI 311 
// Graph class cpp
// Author: Tanner Hart

#include <iostream>
#include "Graph.h"
#include <queue>
#include <limits>
using namespace std;

//do not change the header files
//implement the following functions and do not introduce new functions

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

bool Graph::isTwoColorable(){
  for (auto& node : nodes) { // 'Reset' all nodes
    node->visited = false;
    node->color = "";
  }

  for (auto& node : nodes) {
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
          if (n->color.empty()) {
            n->color = (curr->color == "red") ? "blue" : "red";
            n->visited = true;
            n->predecessor = curr;
            q.push(n);
          }
          else if (n->color == curr->color) {
            return false;
          }
        }
      }
    }
  }
  return true; // default case
}



// Lab 8 functions - graph part 2

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
  for (auto& node : nodes) {
    node->visited = false;
    node->predecessor = nullptr;
  }

  
  for (auto& node : nodes) {
    if (!node->visited && hasCycleRecur(node->id)) {
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
          if (hasCycleRecur(neighbor->id)) return true;
      } else if (neighbor != nodes[s]->predecessor) {
          return true;
      }
  }
    return false;
}

bool Graph::isReachable(int u, int v){
  if (u >= nodes.size() || v >= nodes.size()) return false; // Check if u or v are out of bounds
  if (u == v) return true; // A node is always reachable from itself - step 1 from class example

  // continue if base cases dont run
  for (auto& node : nodes) {
    node->visited = false;
  }

  queue<shared_ptr<Node>> q;
  auto n = nodes[u];
  n->visited = true;
  q.push(n);

  while (!q.empty()) {
    auto current = q.front();
    q.pop();
    if (current->id == v) return true;

    for (auto& neighbor : current->neighbors) {
      if (!neighbor->visited) {
          neighbor->visited = true;
          q.push(neighbor);
      }
    }
  }
  return false; // Not reachable, defaut case
}