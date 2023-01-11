#include <iostream>
#include <queue>
#include <climits>
#include "D:\clones\DSA-1\DSA CN\trees\tree.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        // cout << "Enter the number of children of " << front->data << endl;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            // cout << "Enter the " << i << " th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int nextInterger(TreeNode<int> *root, int x)
{
    int n = INT_MAX;
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    if (root->data < n && root->data > x)
    {
        n = root->data;
    }
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNodes.push(front->children[i]);
            if (front->children[i]->data < n && front->children[i]->data > x)
            {
                n = front->children[i]->data;
            }
        }
    }
    return n;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int n;
    cin >> n;
    cout << nextInterger(root, n);
}