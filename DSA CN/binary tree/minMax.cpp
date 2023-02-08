#include<iostream>
#include "./treeNode.h"
#include <climits>
#include <queue>
using namespace std;
BinaryTreeNode<int> *takeInputBetter()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChildData;
        cout << "Enter left child of " << front->data << endl;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            front->left = leftChild;
            pendingNodes.push(leftChild);
        }

        int rightChildData;
        cout << "Enter right child of " << front->data << endl;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            front->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}
pair<int,int> minMax(BinaryTreeNode<int> * root){
    if(root == NULL){
        pair<int, int> p;
        p.first = INT_MAX; // min
        p.second = INT_MIN; // max
        return p;
    }

    pair<int,int> leftAns = minMax(root->left);
    pair<int, int> rightAns = minMax(root->right);
    pair<int, int> p;
    p.first = min(root->data, min(leftAns.first,rightAns.first));
    p.second = max(root->data, max(leftAns.second, rightAns.second));
    return p;
}

int main(){
        BinaryTreeNode<int> *root = takeInputBetter();
        pair<int, int> p = minMax(root);
        cout << "min " << p.first << " max " << p.second;
}