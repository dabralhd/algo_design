// Validate Binary Search Tree

#include <iostream>
#include <climits>

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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return false;
        return checkValidBST(root);
        
    }

    bool checkValidBST(TreeNode* root) {
        if(root==nullptr) return true;

        return checkValidBST(root->left) && 
               ((root->left == nullptr) || (root->left->val < root->val)) &&
               checkValidBST(root->right) &&
               ((root->right == nullptr) || (root->right->val > root->val))

               


    }
};


int main() {
    return 0;
}