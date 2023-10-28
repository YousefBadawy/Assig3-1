// BST.cpp
#include "BST.h"

template <typename KeyType, typename DataType>
BST<KeyType, DataType>::BST() : root(nullptr) {}

template <typename KeyType, typename DataType>
BST<KeyType, DataType>::~BST() {
    clear();
}

template <typename KeyType, typename DataType>
void BST<KeyType, DataType>::insert(const KeyType& key, const DataType& data) {
    insertRecursive(root, key, data);
}

template <typename KeyType, typename DataType>
Node<KeyType, DataType>* BST<KeyType, DataType>::search(const KeyType& key) {
    return searchRecursive(root, key);
}

template <typename KeyType, typename DataType>
void BST<KeyType, DataType>::inOrderTraverse(void (visit)(Node<KeyType, DataType>)) {
    inOrderTraverseRecursive(root, visit);
}

template <typename KeyType, typename DataType>
void BST<KeyType, DataType>::clear() {
    clearRecursive(root);
}

template <typename KeyType, typename DataType>
void BST<KeyType, DataType>::insertRecursive(Node<KeyType, DataType>*& current, const KeyType& key,
    const DataType& data) {
    if (current == nullptr) {
        current = new Node<KeyType, DataType>(key, data);
    }
    else if (key < current->key) {
        insertRecursive(current->left, key, data);
    }
    else if (key > current->key) {
        insertRecursive(current->right, key, data);
    }
    else {
        // Handle duplicate key if needed
    }
}

template <typename KeyType, typename DataType>
Node<KeyType, DataType>* BST<KeyType, DataType>::searchRecursive(Node<KeyType, DataType>* current,
    const KeyType& key) {
    if (current == nullptr || current->key == key) {
        return current;
    }

    if (key < current->key) {
        return searchRecursive(current->left, key);
    }
    else {
        return searchRecursive(current->right, key);
    }
}

template <typename KeyType, typename DataType>
void BST<KeyType, DataType>::inOrderTraverseRecursive(Node<KeyType, DataType>* current,
    void (visit)(Node<KeyType, DataType>)) {
    if (current != nullptr) {
        inOrderTraverseRecursive(current->left, visit);
        visit(current);
        inOrderTraverseRecursive(current->right, visit);
    }
}

template <typename KeyType, typename DataType>
void BST<KeyType, DataType>::clearRecursive(Node<KeyType, DataType>*& current) {
    if (current != nullptr) {
        clearRecursive(current->left);
        clearRecursive(current->right);
        delete current;
        current = nullptr;
    }
}
