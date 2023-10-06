/*********************************************************
 * (06/10/23)
 *
 *                      Day - 2
 *
 *
543. Diameter of Binary Tree
https://leetcode.com/problems/diameter-of-binary-tree/description/

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

***********************************************************/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int dia = 0;
    int helper(TreeNode* root){
        if(root == NULL) return 0;

        int left = 0; int right =0;
        if(root->left) left = helper(root->left);
        if(root->right ) right = helper(root->right);

        int maxi = max(left,right);
        dia = max(dia, max(maxi, left+right));
        return maxi +1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return dia;
    }
};