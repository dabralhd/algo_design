https://leetcode.com/explore/interview/card/top-interview-questions-medium/108/trees-and-graphs/786/

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
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
   
    // recursive methond for inorder traversal
    vector<int> inorderTraversal_rec(TreeNode* root) {
        std::vector<int> nums;
        if(root!=nullptr) {
            vector<int> t_nums;
            // visit left subtree
            t_nums = inorderTraversal_rec(root->left);
            nums.insert(nums.end(), t_nums.begin(), t_nums.end());

            // visit node
            nums.push_back(root->val);

            // visit right subtree
            t_nums = inorderTraversal_rec(root->right);
            nums.insert(nums.end(), t_nums.begin(), t_nums.end());
        }

        return nums;        
    }

  
};