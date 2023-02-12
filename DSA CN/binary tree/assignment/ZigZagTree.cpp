#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void zigZagOrder(BinaryTreeNode<int>* root){
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    bool count = true;
    while(!pendingNodes.empty()){
        BinaryTreeNode<int> *current = pendingNodes.front();
        pendingNodes.pop();
        if(current != NULL){
            if(count == true){
                cout << current->data << " ";
                if(current->right)
                    pendingNodes.push(current->right);
                if(current->left)
                    pendingNodes.push(current->left);
            }
            if(count == false){
                cout << current->data << " ";
                if(current->left) pendingNodes.push(current->left);
                if(current->right) pendingNodes.push(current->right);
                
            }
        }else{
            if(pendingNodes.empty())break;
            else
                pendingNodes.push(NULL);
            count = !count;
            cout << endl;
        }
    }
}



int main() {
    BinaryTreeNode<int>* root = takeInput();
    zigZagOrder(root);
}