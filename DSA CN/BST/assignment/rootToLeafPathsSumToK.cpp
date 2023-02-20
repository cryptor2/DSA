#include <iostream>
#include <queue>
#include <vector>
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

void rootToLeafPathsSumToKHelper(BinaryTreeNode<int> *root, int k, vector<int> path)
{
    if (root == NULL)
        return;
    path.push_back(root->data);
    k = k - root->data;
    if (k == 0)
    {
        if (!root->left && !root->right)
        {
            {
                for (int i = 0; i < path.size(); i++)
                {
                    cout << path.at(i) << " ";
                }
                cout << endl;
            }
        }
    }
    

    rootToLeafPathsSumToKHelper(root->left, k, path);
    rootToLeafPathsSumToKHelper(root->right, k, path);
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
        return;
    vector<int> path;
    rootToLeafPathsSumToKHelper(root, k, path);
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    delete root;
}