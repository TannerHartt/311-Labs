// Lab 5 Skeleton - rename it to "AVLTree.cpp"


#include <iostream>
#include <limits.h>
#include "AVLTree.h"
using namespace std;

//do not change anything in the above
//implement the following methods, starting here
AVLTree::AVLTree() : root(nullptr), size(0) {}

shared_ptr<AVLNode> AVLTree::getRoot(){
  return root;
}

int AVLTree::getSize(){
  return size;
}

shared_ptr<AVLNode> AVLTree::search(int val){
  return search(root, val);
}

shared_ptr<AVLNode> AVLTree::search(shared_ptr<AVLNode> n, int val){
  if (!n || n->value == val) 
    return n;
  if (val < n->value)
    return search(n->left, val);
  else
    return search(n->right, val);
}

shared_ptr<AVLNode> AVLTree::minimum(){
  return minimum(root);
}

shared_ptr<AVLNode> AVLTree::minimum(shared_ptr<AVLNode> n){
  while (n->left) {
    n = n->left;
  }
  return n;
}

shared_ptr<AVLNode> AVLTree::maximum(){
  return maximum(root);
}

shared_ptr<AVLNode> AVLTree::maximum(shared_ptr<AVLNode> n) {
  while (n->right) {
    n = n->right;
  }
  return n;
}

int getHeight(shared_ptr<AVLNode> n){
  if (!n) return -1;
  return max(getHeight(n->left), getHeight(n->right));
}

int getBalanceFactor(shared_ptr<AVLNode> n){
  if (!n) return -1;
  return getHeight(n->right) - getHeight(n->left);
}

void AVLTree::insertValue(int val){
  root = insertValue(root, val);
}

shared_ptr<AVLNode> AVLTree::insertValue(shared_ptr<AVLNode> n, int val){
  if (!n) {
    n = shared_ptr<AVLNode>(new AVLNode(val));
    size++;
    return n;
  } 
  
  if (val > n->value) {
      n->right = insertValue(n->right, val);
  } if (val < n->value) { 
      n->left = insertValue(n->left, val);
  } else {
      return n; // Defautl case to catch duplicates
  }

  return rebalance(n);
}

void AVLTree::deleteValue(int val){
  root = deleteValue(root, val);
}

shared_ptr<AVLNode> AVLTree::deleteValue(shared_ptr<AVLNode> n, int val){
  if (!n) {
    return nullptr;
  }

  // Standard BST delete
  if (val < n->value) {
    n->left = deleteValue(n->left, val);
  } else if (val> n->value) {
    n->right = deleteValue(n->right, val);
  } else {
    size--;
    // one or less childrne
    if ((n->left == nullptr) || (n->right == nullptr)) {
      shared_ptr<AVLNode> temp = n->left ? n->left : n->right;

      // No child
      if (temp == nullptr) {
        temp = n;
        n = nullptr;
      } else {
        // One child
        n = temp;
      }
    } else {
      shared_ptr<AVLNode> temp = minimum(n->right);
      n->value = temp->value;
      n->right = deleteValue(n->right, temp->value);
    }
  }

  // Check if rebalance is necessary
  return rebalance(n);
}

shared_ptr<AVLNode> AVLTree::rebalance(shared_ptr<AVLNode> n){
    if (!n) return nullptr;

    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    int bal = getBalanceFactor(n);

    // Left Left Case
    if (bal > 1 && getBalanceFactor(n->left) >= 0) {
        return rotateRight(n);
    }

    // Left Right Case
    if (bal > 1 && getBalanceFactor(n->left) < 0) {
        return rotateLeftRight(n);
    }

    // Right Right Case
    if (bal < -1 && getBalanceFactor(n->right) <= 0) {
        return rotateLeft(n);
    }

    // Right Left Case
    if (bal < -1 && getBalanceFactor(n->right) > 0) {
        return rotateRightLeft(n);
    }

    return n;
}


shared_ptr<AVLNode> AVLTree::rotateLeft(shared_ptr<AVLNode> n){
    shared_ptr<AVLNode> y = n->right;
    shared_ptr<AVLNode> x = y->left;
    y->left = n;
    n->right = x;
    n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    n->balanceFactor = getHeight(n->left) - getHeight(n->right);
    y->balanceFactor = getHeight(y->left) - getHeight(y->right);
    return y;
}

shared_ptr<AVLNode> AVLTree::rotateRight(shared_ptr<AVLNode> n){
  shared_ptr<AVLNode> x = n->left;
  shared_ptr<AVLNode> y = n->right;
  x->right = n;
  n->left = y;
  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  x->height = 1 + max(getHeight(x->left), getHeight(x->right));
  n->balanceFactor = getHeight(n->left) - getHeight(n->right);
  x->balanceFactor = getHeight(x->left) - getHeight(x->right);
  return x;
}

// shared_ptr<AVLNode> AVLTree::rotateLeftRight(shared_ptr<AVLNode> n){
//   n->left = rotateLeft(n->left);
//   rebalance(n);
//   return rotateRight(n);
// }

// shared_ptr<AVLNode> AVLTree::rotateRightLeft(shared_ptr<AVLNode> n){
//   n->right = rotateRight(n->right);
//   rebalance(n);
//   return rotateLeft(n);
// }

shared_ptr<AVLNode> AVLTree::rotateLeftRight(shared_ptr<AVLNode> n) {
  n->left = rotateLeft(n->left);
  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  n->balanceFactor = getBalanceFactor(n);
  return rotateRight(n);
}

shared_ptr<AVLNode> AVLTree::rotateRightLeft(shared_ptr<AVLNode> n) {
  n->right = rotateRight(n->right);
  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
  n->balanceFactor = getBalanceFactor(n);
  return rotateLeft(n);
}

void AVLTree::preOrder(shared_ptr<AVLNode> n, vector<shared_ptr<AVLNode>> &order){
  if (!n)
    return;

  order.push_back(n);
  preOrder(n->left, order);
  preOrder(n->right, order);
}

void AVLTree::inOrder(shared_ptr<AVLNode> n, vector<shared_ptr<AVLNode>> &order){
  if (!n)
    return;

  inOrder(n->left, order);
  order.push_back(n);
  inOrder(n->right, order);
}

void AVLTree::postOrder(shared_ptr<AVLNode> n, vector<shared_ptr<AVLNode>> &order){
  if (!n)
    return;

  postOrder(n->left, order);
  postOrder(n->right, order);
  order.push_back(n);
}

