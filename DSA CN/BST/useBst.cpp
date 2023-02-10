#include<iostream>
#include "../binary tree/treeNode.h"
#include <queue>
using namespace std;

void levelOrderTraversal(BinaryTreeNode<int> *root){
    if(root == NULL)
    return;

    queue<BinaryTreeNode<int> *> pendingNodes;
    cout << root->data << " " << endl ;
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
    if(front->right != NULL){
            cout << front->right->data << " " ;
            pendingNodes.push(front->right);
    }
    if(nl == front){
            nl = pendingNodes.back();
            cout << endl;
    }
    }
} 


BinaryTreeNode<int> * constructBST(int arr[], int low, int high){
    if(low > high)
        return NULL;

    int mid = (low + high) / 2;
    int data = arr[mid];

    BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
    node->left = constructBST(arr, low, mid - 1);
    node->right = constructBST(arr, mid + 1, high);
    return node;
}

int size(BinaryTreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int l = size(root->left);
    int r = size(root->right);
    return 1 + l + r;

}
int sum(BinaryTreeNode<int> *root){
    if(root == NULL)
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

int max(BinaryTreeNode<int>* root){
    if(root->left != NULL)
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

//using recursion
int min(BinaryTreeNode<int>* root){
    if(root->left != NULL)
        return min(root->left);
        else
        return root->data;
}

bool find(BinaryTreeNode<int>* root, int val){
    if(root == NULL){
        return false;
    }
    if(val < root->data)
        return find(root->left, val);
    else if(val > root->data)
        return find(root->right, val);
    else
        return true;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    BinaryTreeNode<int> *root = constructBST(arr, 0, 8);
    // levelOrderTraversal(root);
    cout << "size " << size(root) << endl;
    cout << "sum " << sum(root) << endl;
    cout << "min " << min(root) << endl;
    cout << "max " << max(root) << endl;
    cout << "find " << find(root, 9) << endl;
}