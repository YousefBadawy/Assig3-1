// BST.h
#pragma once

template <typename KeyType, typename DataType>
struct Node {
    KeyType key;
    DataType data;
    Node* left;
    Node* right;

    Node(const KeyType& k, const DataType& d) : key(k), data(d), left(nullptr), right(nullptr) {}
};

template <typename KeyType, typename DataType>
class BST {
public:
    BST();
    ~BST();

    void insert(const KeyType& key, const DataType& data);
    Node<KeyType, DataType>* search(const KeyType& key);
    void inOrderTraverse(void (visit)(Node<KeyType, DataType>));
    void clear();

    Node<KeyType, DataType>* getRoot() const {
        return root;
    }

private:
    Node<KeyType, DataType>* root;

    void insertRecursive(Node<KeyType, DataType>*& current, const KeyType& key, const DataType& data);
    Node<KeyType, DataType>* searchRecursive(Node<KeyType, DataType>* current, const KeyType& key);
    void inOrderTraverseRecursive(Node<KeyType, DataType>* current, void (visit)(Node<KeyType, DataType>));
    void clearRecursive(Node<KeyType, DataType>*& current);
};

#include "BST.cpp"
