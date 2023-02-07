#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    unique_ptr<TreeNode> right, left;    
    TreeNode(int _val=0) : val {_val} {}
};

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

ostream& operator<<(ostream& os, const vector<int>& vi) {
    for(auto i:vi)
        os << i << " ";
    return os;
}

ostream& operator<<(ostream& os, const unique_ptr<TreeNode>& root) {
    vector<int> vi;
    inorder(root, vi);   
    os << "\tinorder: " << vi << endl;
    vi.erase(vi.begin(), vi.end());

    preorder(root, vi);   
    os << "\tpreorder: " << vi << endl;
    vi.erase(vi.begin(), vi.end());

    postorder(root, vi);   
    os << "\tpostorder: " << vi << endl;
    vi.erase(vi.begin(), vi.end());

    return os;
}

int findMin(unique_ptr<TreeNode>& root) {    
    auto ptr = root.get();
    while(ptr && ptr->left) {
        ptr = ptr->left.get();
    }
        
    return ptr->val;
}

int findMax(unique_ptr<TreeNode>& root) {
    if(root && root->right)
        findMax(root->right);
    else if(root)   
        return root->val;
    return -1;
}

void remove(int x, unique_ptr<TreeNode>& root){
    if(root) {
        if(x < root->val)
            remove(x, root->left);
        else if(root->val < x)
            remove(x, root->right);
        else if(root->left && root->right) {
            unique_ptr<TreeNode> *p = &(root);
            auto r = &((*p)->right);
            while((*r)->left) {
                p = r;
                r = &((*r)->left);
            }
            root->val = (*r)->val;
            (*r).reset(nullptr);

        } else {
            auto& x = (root->left)? root->left : root->right;
            root->val = x->val;        
        }
    } 
}

unique_ptr<TreeNode>& findMax1(unique_ptr<TreeNode>& root) {
    unique_ptr<TreeNode>* ptr = &root;
    while(*ptr && (*ptr)->right)
        ptr = &((*ptr)->right);
    return *ptr;    
}

int main() {
    unique_ptr<TreeNode> root = make_unique<TreeNode>(10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 7);
    cout << root;

    cout <<"removing 5: " << endl;
    remove(5, root);
    cout <<root;

    cout <<"removing 15: " << endl;
    remove(15, root);
    cout <<root;


    return 0;
}