#include<iostream>
#include <queue>
#include "./treeNode.h"
using namespace std;

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int search(int *in, int inS, int inE, int x){
    for (int i = inS; i < inE; i++){
        if(in[i] == x)
            return i;
    }
}

BinaryTreeNode<int>* buildTreeHelper(int* in, int* post, int inS, int inE, int posS, int posE){
    if(inS > inE){
        return NULL;
    }
    int rootNode = inS;
    while(in[rootNode]!= post[posE]){
        rootNode++;
        
    }

    int totalLenght = rootNode - inS;

    int totalLenght = rootNode - inS;
    int lInS = inS;
    int lInE = rootNode-1;
    int lPosS = posS ;
    int lPosE = posS + totalLenght-1;
    int rInS= rootNode+1;
    int rInE = inE;
    int rPosS =  posS+totalLenght;
    int rPosE = posE-1;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(post[posE]);
    root->left = buildTreeHelper(in, post, lInS, lInE, lPosS, lPosE);
    root->right = buildTreeHelper(in, post, rInS, rInE, rPosS, rPosE);
    return root;
}


BinaryTreeNode<int>* buildTree(int *postorder, int posLength, int *inorder, int inLength) {
    BinaryTreeNode<int> *root = buildTreeHelper(inorder, postorder, 0, inLength - 1, 0,  posLength- 1);
    return root;
}

int main(){
    int pos[] = {2, 9, 3, 6, 10, 5};
    int in[] = {2, 6, 3, 9, 5, 10};
    BinaryTreeNode<int> *root = buildTree(pos, 6, in, 6);
    printLevelATNewLine(root);
}
