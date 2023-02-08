#include<iostream>
#include "./treeNode.h"
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

int heightOfTree(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}

// int diameter(BinaryTreeNode<int>*root){
//     if(root == NULL)
//         return 0;
//     int height = heightOfTree(root);
//     int diaL = diameter(root->left);
//     int diaR = diameter(root->right);
//     return max(height, max(diaL, diaR));
// }


pair<int, int> diameterOFTree(BinaryTreeNode<int>* root){
if(root == NULL){
    pair<int, int> p;
    p.first = 0;
    p.second = 0;
    return p;
}

pair<int, int> left = diameterOFTree(root->left);
pair<int, int> right = diameterOFTree(root->right);
int ld = left.second;
int lh = left.first;
int rd = right.second;
int rh = right.first;

int height = 1 + max(lh, rh);
int diameter = max(lh + rh, max(ld, rd));
pair<int, int> p;
p.first = height;
p.second = diameter;
return p;
}

int main(){
BinaryTreeNode<int> *root = takeInputBetter();
pair<int, int> p = diameterOFTree(root);
cout << "heightOFtree " << p.first;
cout << "diameter " << p.second;
}