#ifndef __BST__
#define __BST__

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    unique_ptr<TreeNode> right, left;    
    TreeNode(int _val=0) : val {_val} {}
};

void inorder(const unique_ptr<TreeNode>& root, vector<int>& vi);
void postorder(const unique_ptr<TreeNode>& root, vector<int>& vi);
void preorder(const unique_ptr<TreeNode>& root, vector<int>& vi);
void insert(unique_ptr<TreeNode>& node, int val);

#endif // __BST__