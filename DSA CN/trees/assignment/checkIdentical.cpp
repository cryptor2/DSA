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
        cout << "Enter the number of children of " << front->data << endl;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter the " << i << " th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

bool checkIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    queue<TreeNode<int> *> q1;
    queue<TreeNode<int> *> q2;
    q1.push(root1);
    q2.push(root2);
    while (!q1.empty() && !q2.empty())
    {
        TreeNode<int> *front1 = q1.front();
        TreeNode<int> *front2 = q2.front();
        if (front1->data != front2->data)
        {
            return false;
        }
        q1.pop();
        q2.pop();
        for (int i = 0; i < front1->children.size(); i++)
        {
            q1.push(front1->children[i]);
            q2.push(front2->children[i]);
        }
    }
    if (!q1.empty() || !q2.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    cout << "Enter the tree1" << endl;
    TreeNode<int> *root1 = takeInputLevelWise();
    cout << "Enter the tree1" << endl;
    TreeNode<int> *root2 = takeInputLevelWise();
    cout << checkIdentical(root1, root2);
}