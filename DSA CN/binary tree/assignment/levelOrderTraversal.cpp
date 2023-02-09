#include<iostream>
#include "../treeNode.h"
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

int checkBalancedHelper(BinaryTreeNode<int> *root){
    if(root == NULL){
        return true;
    }

    int l = checkBalancedHelper(root->left);
    int r = checkBalancedHelper(root->right);
    
    if(l == -1 || r == -1){
        return -1;
    }
    int m = max(l, r);
    if(m-l <= 1 && m-r <= 1){
        return m + 1;
    }else
    return -1;
}

void levelOrderTraversal(BinaryTreeNode<int> *root){
    if(root == NULL)
    return;

    queue<BinaryTreeNode<int> *> pendingNodes;
    cout << root->data << " " << endl ;
    pendingNodes.push(root);
    BinaryTreeNode<int> *nl = root;
    while (!pendingNodes.empty())
    {
    BinaryTreeNode<int> *front = pendingNodes.front();
    pendingNodes.pop();
    
    if (front->left != NULL)
    {
            cout << front->left->data << " ";
            pendingNodes.push(front->left);
            
        }
    if(front->right != NULL){
            cout << front->right->data << " " ;
            pendingNodes.push(front->right);
    }
    if(nl == front){
            nl = pendingNodes.back();
            cout << endl;
    }
    }
} 

int main(){
    BinaryTreeNode<int> *root = takeInputBetter();
    levelOrderTraversal(root);
}