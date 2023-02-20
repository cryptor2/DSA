#include <iostream>
#include <queue>
#include <climits>
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

class largestBSTSubtreeReturn
{
public:
    int maximum;
    int minimum;
    int height;
    bool isBST;
};

largestBSTSubtreeReturn
largestBSTSubtree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        largestBSTSubtreeReturn ans;
        ans.maximum = INT_MIN;
        ans.minimum = INT_MAX;
        ans.height = 0;
        ans.isBST = true;
        return ans;
    }

    largestBSTSubtreeReturn leftAns = largestBSTSubtree(root->left);
    largestBSTSubtreeReturn rightAns = largestBSTSubtree(root->right);

    int minimum = min(root->data, (leftAns.minimum, leftAns.minimum));
    int maximum = max(root->data, (leftAns.maximum, rightAns.maximum));
    int height = max(leftAns.height, rightAns.height);
    bool isBST = (root->data > leftAns.maximum) && (root->data < rightAns.minimum) && leftAns.isBST && rightAns.isBST;
    if (isBST)
        height++;

    largestBSTSubtreeReturn ans;
    ans.maximum = maximum;
    ans.minimum = minimum;
    ans.height = height;
    ans.isBST = isBST;
    return ans;
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << largestBSTSubtree(root).height;
    delete root;
}