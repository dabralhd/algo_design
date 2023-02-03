#include "bst.h"

void inorder(const unique_ptr<TreeNode>& root, vector<int>& vi) {    
    if (root!=nullptr) {
        inorder(root->left, vi);
        vi.push_back(root->val);
        inorder(root->right, vi);        
    }
}

void postorder(const unique_ptr<TreeNode>& root, vector<int>& vi) {    
    if (root!=nullptr) {
        postorder(root->left, vi);
        postorder(root->right, vi);        
        vi.push_back(root->val);
    }
}

void preorder(const unique_ptr<TreeNode>& root, vector<int>& vi) {    
    if (root!=nullptr) {
        vi.push_back(root->val);
        preorder(root->left, vi);
        preorder(root->right, vi);        
    }
}

void insert(unique_ptr<TreeNode>& node, int val) {
    if(node==nullptr) {
        node = make_unique<TreeNode>(val);
    } else if (val < node->val) {
        insert(node->left, val);
    } else if (node->val < val) {
        insert(node->right, val);
    } else {
        // match        
    }
}