/*********************************************************
 * (06/10/23)
 *
 *                      Day - 2
 *
 *
110. Balanced Binary Tree

https://leetcode.com/problems/balanced-binary-tree/description/

Given a binary tree, determine if it is height-balanced.
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
class Solution
{
public:
    bool ans = true;
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = 0, right = 0;
        if (root->left)
            left = height(root->left);
        if (root->right)
            right = height(root->right);

        if (abs(left - right) > 1)
            ans = false;
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        height(root);
        return ans;
    }
};