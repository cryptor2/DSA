#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;


BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    
    vector<Node<int> *> ans; //create vector
    queue<BinaryTreeNode<int> *> pendingNodes;  // create queue
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    BinaryTreeNode<int> *current = NULL;
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    while(!pendingNodes.empty()){
        current = pendingNodes.front();
        pendingNodes.pop();
        if(current != NULL){
            if(head == NULL){
                head = new Node<int>(current->data);
                tail = head;
                // cout << "head set"<< endl;
            }
            else{
                tail->next = new Node<int>(current->data);
                tail = tail->next;
            }
            if(current->left != NULL){
                    pendingNodes.push(current->left);
            // cout << "left done" << endl;
            }
            if(current->right !=NULL)
                    pendingNodes.push(current->right);
        }
        if(current==NULL){
            ans.push_back(head);
            // cout << "push" << endl;
            head = NULL;
            tail = NULL;
            if(pendingNodes.empty()) break;
            if(pendingNodes.size()!=0)
                pendingNodes.push(NULL);
    }}
    return ans;
}


int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}



