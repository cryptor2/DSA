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

class isBSTReturn
{
public:
    bool isBST;
    int minimum;
    int maximum;
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

void levelOrderTraversal(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> pendingNodes;
    cout << root->data << " " << endl;
    pendingNodes.push(root);
    BinaryTreeNode<int> *nl = root;
    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        if (front->left != NULL)
        {
            cout << front->left->data << " ";
            pendingNodes.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << front->right->data << " ";
            pendingNodes.push(front->right);
        }
        if (nl == front)
        {
            nl = pendingNodes.back();
            cout << endl;
        }
    }
}

BinaryTreeNode<int> *constructBST(int arr[], int low, int high)
{
    if (low > high)
        return NULL;

    int mid = (low + high) / 2;
    int data = arr[mid];

    BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
    node->left = constructBST(arr, low, mid - 1);
    node->right = constructBST(arr, mid + 1, high);
    return node;
}

int size(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = size(root->left);
    int r = size(root->right);
    return 1 + l + r;
}
int sum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int l = sum(root->left);
    int r = sum(root->right);
    return root->data + l + r;
}
// int max (BinaryTreeNode<int> *root){
//     int max;
//     BinaryTreeNode<int> *temp = root;
//     while(temp -> right!= NULL){
//         temp = temp->right;
//     }
//     return temp->data;
// }

// using recursion

int max(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    if (root->left != NULL)
        return max(root->right);
    else
        return root->data;
}

// int min(BinaryTreeNode<int> *root){
//     int min;
//     BinaryTreeNode<int> *temp = root;
//     while(temp->left!= NULL){
//         temp = temp->left;
//     }
//     return temp->data;
// }

// using recursion
int min(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MAX;
    if (root->left != NULL)
        return min(root->left);
    else
        return root->data;
}

bool find(BinaryTreeNode<int> *root, int val)
{
    if (root == NULL)
    {
        return false;
    }
    if (val < root->data)
        return find(root->left, val);
    else if (val > root->data)
        return find(root->right, val);
    else
        return true;
}

void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
        return;
    if (root->data > k1)
        elementsInRangeK1K2(root->left, k1, k2);
    if (root->data >= k1 && root->data <= k2)
        cout << root->data << " ";
    if (root->data < k2)
        elementsInRangeK1K2(root->right, k1, k2);
}

bool isBST1(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    int lmax = max(root->left);
    // cout << lmax << " ";
    int rmin = min(root->right);
    // cout << rmin;

    bool out = (root->data > lmax) && (root->data <= rmin) && isBST1(root->left) && isBST1(root->left);
    return out;
}

isBSTReturn isBST2(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        isBSTReturn op;
        op.isBST = true;
        op.minimum = INT_MAX;
        op.maximum = INT_MIN;
        return op;
    }

    isBSTReturn leftAns = isBST2(root->left);
    isBSTReturn rightAns = isBST2(root->right);

    int minimum = min(root->data, leftAns.minimum);
    int maximum = max(root->data, rightAns.maximum);
    bool out = (root->data > leftAns.maximum) && (root->data <= rightAns.minimum) && leftAns.isBST && rightAns.isBST;
    isBSTReturn op;
    op.isBST = out;
    op.maximum = maximum;
    op.minimum = minimum;
    return op;
}

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == NULL)
        return true;
    if (root->data < min || root->data > max)
    {
        return false;
    }
    bool isLeftOk = isBST3(root->left, min, root->data);
    bool isRightOk = isBST3(root->right, root->data, max);
    return isLeftOk && isRightOk;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();

    cout << "ans " << isBST3(root);
}