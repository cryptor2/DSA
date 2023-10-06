/*********************************************************
 * (06/10/23)
 *
 *                      Day - 2
 *
 *
124. Binary Tree Maximum Path Sum
https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

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
    int maxSum = INT_MIN;
    int helper(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = 0, right = 0;
        if (root->left)
            left = helper(root->left);
        if (root->right)
            right = helper(root->right);

        int lr = max(left, right);

        maxSum = max(maxSum, max(root->val, max(lr, left + right) + root->val));
        return max(root->val, lr + root->val);
    }
    int maxPathSum(TreeNode *root)
    {
        helper(root);
        return maxSum;
    }
};