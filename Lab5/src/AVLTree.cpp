#include <iostream>
#include <limits.h>
#include "AVLTree.h"
using namespace std;

//do not change anything in the above
//implement the following methods, starting here

AVLTree::AVLTree() : root(nullptr), size(0) {}
  
shared_ptr<AVLNode> AVLTree::getRoot() {
  return root;
}

int AVLTree::getSize() {
  return size;
}

shared_ptr<AVLNode> AVLTree::search(int val) {
  return search(root, val);
}

shared_ptr<AVLNode> AVLTree::search(shared_ptr<AVLNode> n, int val) {
  if (!n || n->value == val) 
    return n;

  if (val < n->value) 
    return search(n->left, val);
  else 
    return search(n->right, val);
}

shared_ptr<AVLNode> AVLTree::minimum() {
  return minimum(root);
}

shared_ptr<AVLNode> AVLTree::minimum(shared_ptr<AVLNode> n) {
  while (n->left) 
    n = n->left;
  return n;
}

shared_ptr<AVLNode> AVLTree::maximum() {
  return maximum(root);
}

shared_ptr<AVLNode> AVLTree::maximum(shared_ptr<AVLNode> n) {
  while (n->right) 
    n = n->right;
  return n;
}

int getHeight(shared_ptr<AVLNode> n) {
  if (!n) return -1;
  return max(getHeight(n->left), getHeight(n->right)) + 1;
}

int getBalanceFactor(shared_ptr<AVLNode> n) {
  if (!n) return 0;
  return getHeight(n->right) - getHeight(n->left);
}

void AVLTree::insertValue(int val) {
  root = insertValue(root, val);
}

shared_ptr<AVLNode> AVLTree::insertValue(shared_ptr<AVLNode> n, int val) {
  if (n == nullptr) {
    n = shared_ptr<AVLNode>(new AVLNode(val));
    size++;
    return n;
  }
  else if (val < n->value)
    n->left = insertValue(n->left, val);
  else if (val > n->value)
    n->right = insertValue(n->right, val);
  else
    return n;

  n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
  n->balanceFactor = getBalanceFactor(n);
  return rebalance(n);
}

void AVLTree::deleteValue(int val) {
  root = deleteValue(root, val);
}

shared_ptr<AVLNode> AVLTree::deleteValue(shared_ptr<AVLNode> n, int val) {
  if (!n)
    return NULL;

  if (val < n->value) { 
    n->left = deleteValue(n->left, val);
  } else if (val > n->value) {
    n->right = deleteValue(n->right, val);
  } else {
    if (n->left && n->right) {
      shared_ptr<AVLNode> temp = minimum(n->right);
      n->value = temp->value;
      n->right = deleteValue(n->right, temp->value);
    }
    else
    {
      shared_ptr<AVLNode> temp = NULL;
      if (n->left) 
        temp = n->left;
      else
        temp = n->right;
      size--;
      return temp;
    }
  }

  n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
  n->balanceFactor = getBalanceFactor(n);
  return rebalance(n);
}

shared_ptr<AVLNode> AVLTree::rebalance(shared_ptr<AVLNode> n) {
  if (!n) 
    return nullptr;
  
  if (n->balanceFactor == 2 && n->right->balanceFactor >= 0)
    return rotateLeft(n);
  else if (n->balanceFactor == 2 && n->right->balanceFactor < 0)
    return rotateRightLeft(n);
  else if (n->balanceFactor == -2 && n->left->balanceFactor <= 0)
    return rotateRight(n);
  else if (n->balanceFactor == -2 && n->left->balanceFactor > 0)
    return rotateLeftRight(n);
  else
    return n;
}

shared_ptr<AVLNode> AVLTree::rotateLeft(shared_ptr<AVLNode> n) {
  if (!n || !n->right) 
    return n;
  
  shared_ptr<AVLNode> x = n->right;
  n->right = x->left;
  n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
  n->balanceFactor = getBalanceFactor(n);
  x->left = n;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  x->balanceFactor = getBalanceFactor(x);
  return x;
}

shared_ptr<AVLNode> AVLTree::rotateRight(shared_ptr<AVLNode> n)
{
  if (!n || !n->left) 
    return n;

  shared_ptr<AVLNode> x = n->left;
  n->left = x->right;                   
  n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
  n->balanceFactor = getBalanceFactor(n);
  x->right = n;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  x->balanceFactor = getBalanceFactor(x);
  return x;
}

shared_ptr<AVLNode> AVLTree::rotateLeftRight(shared_ptr<AVLNode> n) {
  n->left = rotateLeft(n->left);
  n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
  n->balanceFactor = getBalanceFactor(n);
  return rotateRight(n);
}

shared_ptr<AVLNode> AVLTree::rotateRightLeft(shared_ptr<AVLNode> n) {
  n->right = rotateRight(n->right);
  n->height = max(getHeight(n->left), getHeight(n->right)) + 1;
  n->balanceFactor = getBalanceFactor(n);
  return rotateLeft(n);
}

void AVLTree::preOrder(shared_ptr<AVLNode> n, vector<shared_ptr<AVLNode>> &order) {
  if (n != nullptr) {
    order.push_back(n);
    preOrder(n->left, order);
    preOrder(n->right, order);
  }
}

void AVLTree::inOrder(shared_ptr<AVLNode> n, vector<shared_ptr<AVLNode>> &order) {
  if (n != nullptr) {
    inOrder(n->left, order);
    order.push_back(n);
    inOrder(n->right, order);
  }
}

void AVLTree::postOrder(shared_ptr<AVLNode> n, vector<shared_ptr<AVLNode>> &order) {
  if (n != nullptr) {
    postOrder(n->left, order);
    postOrder(n->right, order);
    order.push_back(n);
  }
}