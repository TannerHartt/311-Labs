#include <iostream>
#include <memory>
#include <vector>
using namespace std;

template <typename T>
class AVLTree
{
private:
    struct Node
    {
        T key;
        Node *left;
        Node *right;
        int height;
        Node(const T &k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node *root;

    // Helper functions
    int height(Node *N)
    {
        if (N == nullptr)
            return 0;
        return N->height;
    }

    int getBalance(Node *N)
    {
        if (N == nullptr)
            return 0;
        return height(N->left) - height(N->right);
    }

    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        return y;
    }

    Node *insert(Node *node, const T &key)
    {
        if (node == nullptr)
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = 1 + std::max(height(node->left), height(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    public:
    AVLTree() : root(nullptr) {}

    void insert(const T& key) {
        root = insert(root, key);
    }

    void printInOrder() {
        inOrder(root);
        std::cout << std::endl;
    }

    // Destructor to deallocate memory
    ~AVLTree() {
        // Implement a destructor to properly deallocate memory of the tree
    }
};

    int main()
    {
        AVLTree<int> tree;
        return 0;
    }