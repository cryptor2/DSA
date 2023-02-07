#include<iostream>
#include <queue>
#include "./treeNode.h"
using namespace std;

int search(int *in, int inS, int inE, int x){
    for (int i = inS; i < inE; i++){
        if(in[i] == x)
            return i;
    }
}

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE)
{
    if(inS > inE){
        return NULL;
    }
    BinaryTreeNode<int> *Node =new BinaryTreeNode<int>(pre[preS]);
    int rootIndex = search(in, inS, inE, pre[preS]);
    int linS = inS;
    int linE = rootIndex-1;
    int lpreS = preS+1;
    int lpreE = linE-linS +lpreS;
    int rinS = rootIndex+1;
    int rinE = inE;
    int rpreS = lpreE+1;
    int rpreE = preE;  
    BinaryTreeNode<int> *left = buildTreeHelper(in, pre, linS, linE, lpreS, lpreE);
    BinaryTreeNode<int> *right = buildTreeHelper(in, pre, rinS, rinE, rpreS, rpreE);
    Node->left = left;
    Node->right = right;
    return Node;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    BinaryTreeNode<int> *root = buildTreeHelper(inorder, preorder, 0, preLength - 1, 0, inLength - 1);
    return root;
}


void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L:" << front->left->data << ",";
            pendingNodes.push(front->left);
        }
        else
            cout << "L:" << -1 << ",";

        if (front->right != NULL)
        {
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        else
            cout << "R:" << -1;
        cout << endl;
    }
}
int main(){
    int pre[] = { 0, 1, 3, 7, 8, 4, 9, 10, 2, 5, 11, 6 };
    int in[] = {7, 3, 8, 1, 9, 4, 10, 0, 11, 5, 2, 6};
    BinaryTreeNode<int> *root = buildTree(pre, 12, in, 12);
    printLevelWise(root);
}