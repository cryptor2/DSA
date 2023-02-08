#include<iostream>
#include "../treeNode.h"
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

int sumOfNodes(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }

    int sumLeft = sumOfNodes(root->left);
    int sumRight = sumOfNodes(root->right);

    return sumLeft + sumRight + root->data;
}

int main(){
    BinaryTreeNode<int> *root = takeInputBetter();
    int sum = sumOfNodes(root);
    cout << sum << endl;
}