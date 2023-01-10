#include <iostream>
#include <queue>
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

int countNode(TreeNode<int> *root, int x)
{
    int ans = 0;
    if (root->data > x)
    {
        ans += 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNode(root->children[i], x);
    }
    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int x;
    cout << "Enter the x value" << endl;
    cin >> x;
    cout << countNode(root, x);
}