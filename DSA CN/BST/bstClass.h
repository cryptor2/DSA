#include <iostream>
#include "treeNode.h"

class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

private:
    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return NULL;
        if (data < node->data)
            node->left = deleteData(data, node->left);
        else if (data > node->data)
            node->right = deleteData(data, node->right);
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else if (node->left == NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin, minNode);
                return node;
            }
        }
    }

public:
    void deleteData(int data)
    {
    }

private:
    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data < root->data)
            node->left = insert(data, node->left);

        else
            node->right = insert(data, node->right);

        return node;
    }

public:
    void insert(int data)
    {
        this->root = insert(data, root);
    }

private:
    bool hasData(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return false;
        if (root->data == data)
            return true;
        if (root->data < data)
            return hasData(data, root->right);
        if (root->data > data)
            return hasData(data, root->left);
    }

public:
    bool hasData(int data)
    {
        return hasData(data, root);
    }
};