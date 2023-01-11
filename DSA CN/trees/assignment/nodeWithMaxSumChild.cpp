#include <iostream>
#include <queue>
#include "D:\clones\DSA-1\DSA CN\trees\tree.h"
using namespace std;

class Pair
{
public:
    TreeNode<int> *ans;
    int sum;
};

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

Pair *nodeWithMaxSumChild(TreeNode<int> *root, Pair *p)
{
    if (root == NULL)
    {
        return NULL;
    }
    int sum = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
        p = nodeWithMaxSumChild(root->children[i], p);
    }
    sum = sum + root->data;
    if (p->sum < sum)
    {
        p->sum = sum;
        p->ans = root;
    }
    return p;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    Pair *ans = new Pair();
    Pair *p = nodeWithMaxSumChild(root, ans);
    cout << "sum " << p->sum << endl;

    return p->ans;
}

void printTreeLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data;
            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *p = maxSumNode(root);
    cout << p->data;
}