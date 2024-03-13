// Lab 3 - BST_skeleton.cpp - rename it to BST.cpp
// Author: Tanner Hart

#include <iostream>
#include <vector>
#include <limits.h>
#include "BST.h"

// ***do not change the headers***

// you solutions go here
// remember that you do not need to implement all of them
// follow the document to see which ones you need to implement

BST::BST()
{
  root = nullptr;
  size = 0;
}

BST::~BST()
{
}

// BST::~BST()
// {
//   deleteTree(root);
//   root = nullptr;
//   size = 0;
// }

// void deleteTree(std::shared_ptr<Node> n)
// {
//   if (n)
//   {
//     deleteTree(n->left);  // Delete left subtree
//     deleteTree(n->right); // Delete right subtree
//     n = nullptr;          // Delete current node
//   }
// }

std::shared_ptr<Node> BST::search(int target)
{
  return search(root, target);
}

std::shared_ptr<Node> BST::search(std::shared_ptr<Node> n, int target)
{
  // if (!n)
  // {
  //   return nullptr;
  // }
  // if (n->value == target)
  // {
  //   return n;
  // }

  // if (target < n->value)
  // {
  //   return search(n->left, target);
  // }
  // else
  // {
  //   return search(n->right, target);
  // }

  return (!n) ? nullptr : (n->value == target) ? n
                      : (target < n->value)    ? search(n->left, target)
                                               : search(n->right, target);
}

std::shared_ptr<Node> BST::minimum()
{
  return nullptr;
}

std::shared_ptr<Node> BST::minimum(std::shared_ptr<Node> n)
{
  return nullptr;
}

std::shared_ptr<Node> BST::maximum()
{
  return nullptr;
}

std::shared_ptr<Node> BST::maximum(std::shared_ptr<Node> n)
{
  return nullptr;
}

void BST::insertValue(int val)
{
  root = insertValue(root, val);
}

std::shared_ptr<Node> BST::insertValue(std::shared_ptr<Node> n, int val)
{
  if (!n)
  {
    std::shared_ptr<Node> n;
    n = std::shared_ptr<Node>(new Node(val));
    size++;
    return n;
  }

  if (val < n->value)
  {
    n->left = insertValue(n->left, val);
  }
  else if (val > n->value)
  {
    n->right = insertValue(n->right, val);
  }
  return n;
}

void BST::deleteValue(int val)
{
}

std::shared_ptr<Node> BST::deleteValue(std::shared_ptr<Node> n, int val)
{
  return nullptr;
}

bool BST::isBST(std::shared_ptr<Node> n)
{
  return isBST(n, INT_MIN, INT_MAX);
}

bool BST::isBST(std::shared_ptr<Node> n, int low, int high)
{
  return (!n) ? true : (n->value <= low || n->value >= high) ? false
                                                             : true;
  return isBST(n->left, low, n->value) && isBST(n->right, n->value, high);
}

void BST::preOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order)
{
  if (!n)
    return;

  order.push_back(n);
  preOrder(n->left, order);
  preOrder(n->right, order);
}

void BST::inOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order)
{
  if (!n)
    return;

  preOrder(n->left, order);
  order.push_back(n);
  preOrder(n->right, order);
}

void BST::postOrder(std::shared_ptr<Node> n, std::vector<std::shared_ptr<Node>> &order)
{
  if (!n)
    return;

  preOrder(n->left, order);
  preOrder(n->right, order);
  order.push_back(n);
}
