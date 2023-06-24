#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <limits>
#include <stack>
#include <string>

using namespace std;
constexpr static int k_invalid_num = numeric_limits<int>::min();

struct TreeNode {
    int val;
    unique_ptr<TreeNode> left, right;
    TreeNode(int v) : 
    val {v}, left {nullptr}, right {nullptr} {}
};

using NodePtrType = unique_ptr<TreeNode>;

NodePtrType get_node(int v) {
    return make_unique<TreeNode>(v);
}

void inorder(const NodePtrType& root) {
    if(root) {
        inorder(root->left);
        cout << root->val << ", ";
        inorder(root->right);        
    }
}

void preorder(const NodePtrType& root) {
    if(root) {
        cout << root->val << ", ";
        preorder(root->left);
        preorder(root->right);        
    }
}

NodePtrType make_tree(const vector<int>& nums) {
    if (nums.empty())
        return nullptr;

    auto tree = get_node(nums[0]);
    queue<TreeNode*> q;
    if (nums.size()) {        
        q.push(tree.get());
        int idx = 1;
        while(!q.empty() && idx<nums.size()) {
            auto& curr = q.front();
            q.pop();
            int val = nums[idx];
            idx++;
            if(val != k_invalid_num) {
                curr->left = get_node(val);
                q.push(curr->left.get());
            }

            if (idx < nums.size())
                val = nums[idx]; 
                idx++;
                if(val != k_invalid_num) {
                    curr->right = get_node(val);
                    q.push(curr->right.get());
                }
        }
    }
    return tree;
}

const TreeNode* get_ptr_to_node_with_value(NodePtrType& root, int v) {
    if(root!=nullptr) {
        if(root->val==v)
            return root.get();       
        auto left_ptr = get_ptr_to_node_with_value(root->left,v);
        return left_ptr? left_ptr : get_ptr_to_node_with_value(root->right,v);
    }
    return nullptr;
}

NodePtrType& get_node_with_value(NodePtrType& root, int v) {
    if(root!=nullptr) {
        if(root->val==v)
            return root;       
        auto& left_ptr = get_node_with_value(root->left,v);
        return left_ptr? left_ptr : get_node_with_value(root->right,v);
    }
    return root;
}


/** algo for finding lca of two nodes **/

struct LCA_Status {
    int num_nodes;
    TreeNode* lca;
    LCA_Status() { num_nodes=0;}
    LCA_Status(int num, TreeNode* ptr=nullptr) : num_nodes{num}, lca{ptr} { }
};


LCA_Status lca_helper(NodePtrType& tree, NodePtrType& first, NodePtrType& second) {
    if (!tree)
        return LCA_Status();

    LCA_Status left_status = lca_helper(tree->left, first, second);
    if (left_status.num_nodes==2)
        return left_status;

    LCA_Status right_status = lca_helper(tree->right, first, second);
    if (right_status.num_nodes==2)
        return right_status;

    int nodes_found = left_status.num_nodes + right_status.num_nodes + 
                        (tree==first? 1: 0) + (tree==second? 1: 0);

    return {nodes_found, nodes_found==2? tree.get():nullptr};
}

TreeNode* get_lca(NodePtrType& tree, NodePtrType& first, NodePtrType& second) {
    LCA_Status status = lca_helper(tree, first, second);
    if(status.num_nodes==2)
        return status.lca;
    return nullptr;
}

void inorder_without_recursion(const NodePtrType& root) {
    if(root==nullptr)
        return;

    TreeNode* curr = root.get();
    stack<TreeNode*> s;
    while (curr && curr->left) {
        s.push(curr);
        curr = curr->left.get();
    }      
    while(curr ) {
        cout << curr->val << " ";
        if (curr->right) {
            curr = curr->right.get();
            while (curr && curr->left) {
                s.push(curr);
                curr = curr->left.get();
            }              
        } else if(!s.empty()) {
            curr = s.top();
            s.pop();
        } else {
            curr = nullptr;
        }
    }
}

struct BalanceStatus {
    bool balanced;
    int height;
    int unbalanced_at;
    BalanceStatus(bool _b=true, int _h=-1, int _at=-1) : balanced {_b}, 
                                                            height {_h}, 
                                                            unbalanced_at {_at} {}
};

BalanceStatus is_height_balanced_helper(NodePtrType& root) {
    if (root) {
        auto left = is_height_balanced_helper(root->left);
        if (!left.balanced)
            return left;
        auto right = is_height_balanced_helper(root->right);
        if (!right.balanced)
            return right;
        BalanceStatus ret;
        ret.height = max(left.height, right.height) + 1;
        ret.balanced = right.balanced && left.balanced && (abs(left.height - right.height) <= 1);
        if(!ret.balanced)
            ret.unbalanced_at = root->val;
        return ret;
    }
    return BalanceStatus();
}

bool is_height_balanced(NodePtrType& root) {
    return is_height_balanced_helper(root).balanced;
}

struct PathSum_Info_Binary {
    unsigned int total;
    unsigned int curr_path_sum;
    PathSum_Info_Binary() : total {0}, curr_path_sum {0} {}
};

void get_pathSum_binary_helper(const NodePtrType& root, PathSum_Info_Binary& info) {
    if(root) {
        info.curr_path_sum = info.curr_path_sum<<1 | root->val;
        if(root->left==nullptr && root->right==nullptr) {
            info.total += info.curr_path_sum;
        } 
        get_pathSum_binary_helper(root->left, info);
        get_pathSum_binary_helper(root->right, info);       
        info.curr_path_sum >>= 1;
    }
}

unsigned int get_pathSum_binary(const NodePtrType& root) {
    PathSum_Info_Binary info;
    get_pathSum_binary_helper(root, info);
    return info.total;
}


void test_traversal(const vector<int>& nums) {   
    auto tree = make_tree(nums); 
    cout << "inorder: ";
    inorder(tree);
    cout << endl;

    cout << "inorder_without_recursion:";
    inorder_without_recursion(tree);
    cout << endl;

    cout << "preorder: ";
    preorder(tree);
    cout << endl;
}

void test_test_traversal_1() {
    vector<int> nums {10,20, 15, 1, k_invalid_num, 17, 100, 2, 3, 70, k_invalid_num, k_invalid_num, 50};
    test_traversal(nums);
}

void test_traversal() {
    test_test_traversal_1();
}

void test_lca_helper(vector<int> nums, int val1, int val2) {
    auto root = make_tree(nums);
    NodePtrType& node1 = get_node_with_value(root, val1);
    NodePtrType& node2 = get_node_with_value(root, val2);
    auto lca = get_lca(root, node1, node2);
    if (lca)
        cout << "found lca for <" << node1->val << ", " << node2->val << ">: "  << lca->val << endl;
    else
        cout << "lca not found!" << endl;
}

void test_lca() {
    test_lca_helper({10,20, 15, 1, k_invalid_num, 17, 100, 2, 3, 70, 
                        k_invalid_num, k_invalid_num, 50}, 
                        2, 3);

    test_lca_helper({10,20, 15, 1, k_invalid_num, 17, 100, 2, 3, 70, 
                        k_invalid_num, k_invalid_num, 50}, 
                        70, 3);

    test_lca_helper({10,20, 15, 1, k_invalid_num, 17, 100, 2, 3, 70, 
                        k_invalid_num, k_invalid_num, 50}, 
                        70, 50);

    test_lca_helper({10,20, 15, 1, k_invalid_num, 17, 100, 2, 3, 70, 
                        k_invalid_num, k_invalid_num, 50}, 
                        70, 10);

    test_lca_helper({10,20, 15, 1, k_invalid_num, 17, 100, 2, 3, 70, 
                        k_invalid_num, k_invalid_num, 50}, 
                        70, 1000);




}

void test_get_node_with_value(vector<int> nums, vector<int> to_check) {
    auto root = make_tree(nums);    
    cout << "inorder for your reference: " << endl;
    inorder(root);
    for(const auto& val : to_check) {
        auto& node = get_node_with_value(root, val);
        cout << "asked for: " << val << ", and got: " << (node? node->val : k_invalid_num) << endl;
    }
    cout << "inorder after calling get_node with value: " << endl;
    inorder(root);
}

void test_get_node_with_value_1() {
        test_get_node_with_value({10,20, 15, 1, k_invalid_num, 17, 100, 2, 3, 70, k_invalid_num, k_invalid_num, 50}, 
                                 {10,20, 15, 1, -1, 25, 17, 100, 2, 3, 300, 70, 1000, -1, -1, 50});

                                }

void test_is_height_balanced_helper(vector<int> nums) {
    auto tree = make_tree(nums);
    cout << "inorder traversal for given tree is: " << endl;
    inorder(tree);
    auto ret = is_height_balanced_helper(tree);
    cout << "is_balanced? " << (ret.balanced? "yes": "no");
    if(ret.balanced)
        cout << endl;
    else    
        cout << ", unbalanced_at: " << ret.unbalanced_at << endl;     
}                                

void test_is_height_balanced() {
    test_is_height_balanced_helper({10,20, 15, 1, k_invalid_num, 17, 100, 2, 3, 70, 
    k_invalid_num, k_invalid_num, 50});
    test_is_height_balanced_helper({1,2,3});
    test_is_height_balanced_helper({1,2,3, k_invalid_num, k_invalid_num, 4, 5, 6});

}

void test_pathsum_binary_helper(const vector<int>& nums) {
    cout << "- test_pathsum_binary_helper" << endl;
    auto tree = make_tree(nums);
    inorder(tree);
    cout << endl<< "binary pathsum for tree is: " << get_pathSum_binary(tree) << endl;
}

void test_pathsum_binary() {
    test_pathsum_binary_helper({1,1,1});
    test_pathsum_binary_helper({1,0,1});
    test_pathsum_binary_helper({1,1,1, 0, k_invalid_num, 1, 0});
    test_pathsum_binary_helper({1, 
    0, 1, 
    0, 1, 0, 0, 
    0, 1, k_invalid_num, 1, k_invalid_num, 0, k_invalid_num, 0,
    k_invalid_num, k_invalid_num, k_invalid_num, k_invalid_num, 0, k_invalid_num, 1, 0,k_invalid_num, k_invalid_num,
    k_invalid_num, k_invalid_num, k_invalid_num, 1, k_invalid_num, k_invalid_num,});
}


int main() {
    //test_traversal();
    //test_get_node_with_value_1();
    //test_lca();
    //test_is_height_balanced();
    test_pathsum_binary();
}