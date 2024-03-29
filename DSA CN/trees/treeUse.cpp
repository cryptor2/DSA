#include <iostream>
#include <queue>
#include "tree.h"
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

void depthOfKnode(TreeNode<int> *root, int k)
{
    if (k == 1)
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            cout << root->children[i]->data << " ";
        }
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        depthOfKnode(root->children[i], k - 1);
    }
}
int heightOfTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int ht = -1;
    for (int i = 0; i < root->children.size(); i++)
    {
        int a;
        a = heightOfTree(root->children[i]);
        if (a > ht)
            ht = a;
    }
    return ht + 1;
}

int maxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = maxDataNode(root->children[i]);
    }
    if (ans > root->data)
        return ans;
    else
        return root->data;
}

int sumOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumOfNodes(root->children[i]);
    }
    return ans + root->data;
}

int countNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNodes(root->children[i]);
    }
    return ans;
}

void printTreeLevelWise(TreeNode<int> *root)
{
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
    }
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

void preorder(TreeNode<int> *root)
{
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }
    cout << root->data;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    // printTree(root);
    // cout << countNodes(root);
    // cout << maxDataNode(root) << endl;
    // cout << heightOfTree(root) << endl;
    depthOfKnode(root, 2);
}