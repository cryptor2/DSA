#include <iostream>
#include <queue>
#include "treeNode.h"
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


void mirror(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int heightOfTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
}
bool findNodeX(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    bool ansL = findNodeX(root->left, x);
    bool ansR = findNodeX(root->right, x);
    return ansL + ansR;
}

int countNode(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNode(root->left) + countNode(root->right);
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

void preorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// int main()
// {
//     BinaryTreeNode<int> *root = takeInputBetter();
//     // inorder(root);
//     // printLevelWise(root);
//     // cout << "No of nodes are: " << countNode(root);
//     // int x;
//     // cout << "Enter the value of X" << endl;
//     // cin >> x;
//     // cout << "x is present " << findNodeX(root, x);
//     // cout << heightOfTree(root);
//     // mirror(root);
//     // printLevelWise(root);
//     // preorder(root);
//     postorder(root);
//     delete root;
// }