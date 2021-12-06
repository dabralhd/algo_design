#inlude <iostream>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/555/

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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int left_max_len = 0;
        int right_max_len = 0;

        if(root->left != nullptr ) {
            left_max_len = maxDepth(root->left)
        }

        if(root->right != nullptr ) {
            right_max_len = maxDepth(root->left)
        }

        if (left_max_len > right_max_len) {
            return left_max_len + 1;
        }

        return right_max_len + 1;
    }

    
};