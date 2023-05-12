#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

struct BSTNode {
    int val;
    BSTNode *left, *right;
    BSTNode(int v) : val{v}, left {nullptr}, right{nullptr} {}
};

void insert(int v, BSTNode*& root) {
    if(root == nullptr)
        root = new BSTNode(v);
    else if(v < root->val)
        insert(v, root->left);
    else if(root->val < v)
        insert(v, root->right);
    else    
        ;
}

void createBSTAt(BSTNode*& root, vector<int> vi) {  
    for(auto i: vi) {
        insert(i, root);
    }
}

void inorder(const BSTNode* root) {
    if (root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}


int findHigherThan(const int target, const BSTNode* root, int status) {
    if(root) {
        if(root->val < target)
           return findHigherThan(target, root->right, status);
        else if(target < root->val)
           return findHigherThan(target, root->left, root->val);
        else if(root->right)
            return findHigherThan(target, root->right, status);
        else 
            return root->val;
    }
    return status;
}

int findHigherThan(const int v, const BSTNode* root) {
    return findHigherThan(v, root, numeric_limits<int>::max());
}

void findKth(const BSTNode* root, int& k, int& kth) {
    if(root && k) {
        findKth(root->right, k, kth);
        if(--k==0) {
            kth = root->val;
            return;
        }
        findKth(root->left, k, kth);
    }    
}

int height(BSTNode* root) {
    if(root==nullptr) 
        return 0;
    return max(height(root->left), height(root->right)) + 1;    
}

struct HeightAndBalance {
    int height;
    bool balance;
    HeightAndBalance(int h, bool b) : height {h}, balance {b} {}
};

HeightAndBalance getBalanceInfo(BSTNode* root) {
    if (!root)
        return {-1, true};
    auto ri = getBalanceInfo(root->right);
    auto li = getBalanceInfo(root->left);
    return { max(ri.height, li.height)+1, ri.balance && li.balance && abs(ri.balance - li.balance)<=1 };
}


void bst_test_inorder_traversal() {
    cout << "------" << "bst_test_inorder_traversal" << "------------" << endl;
    vector<int> vi {100, 50, 200, 10, 60, 125, 300, 70};
    cout << "creating BST from vector: ";
    for(auto i : vi)
        cout << i << " ";
    cout << endl;
    BSTNode* root = nullptr;
    createBSTAt(root, vi);
    cout <<"doing inorder traversal of bst: " << endl;
    inorder(root);    
}

void bst_test_findHigherThan() {
    cout << endl << "--------" << "bst_test_findHigherThan" << "---------" << endl;
    vector<int> vi {100, 50, 200, 10, 60, 125, 300, 70, 140};
    cout << "creating BST from vector: ";
    for(auto i : vi)
        cout << i << " ";
    cout << endl;
    BSTNode* root = nullptr;
    createBSTAt(root, vi);
    cout <<"doing inorder traversal of bst: " << endl;    
    inorder(root);    
    cout << "finding smallest value higher than 125: " <<  findHigherThan(125, root) << endl;
    cout << "finding smallest value higher than 135: " <<  findHigherThan(135, root) << endl;
    cout << "finding smallest value higher than 40: " <<  findHigherThan(40, root) << endl;
    cout << "finding smallest value higher than 70: " <<  findHigherThan(70, root) << endl;
    cout << "finding smallest value higher than 210: " <<  findHigherThan(210, root) << endl;
    cout << "finding smallest value higher than 5: " <<  findHigherThan(5, root) << endl;
    cout << "finding smallest value higher than 500: " <<  findHigherThan(500, root) << endl;
}

void test_find_kth() {
    cout << endl << "--------" << "test_find_kth" << "---------" << endl;
    vector<int> vi {100, 50, 200, 10, 60, 125, 300, 70, 140};
    cout << "creating BST from vector: ";
    for(auto i : vi)
        cout << i << " ";
    cout << endl;
    BSTNode* root = nullptr;
    createBSTAt(root, vi);
    cout <<"doing inorder traversal of bst: " << endl;    
    inorder(root);    
    int elem = 0;

    int k = 2;
    cout << endl << "finding largest element of rank " << k << ": " ;
    findKth(root, k, elem);
    cout << elem << endl;

    k = 5;
    cout << endl << "finding largest element of rank " << k << ": " ;
    findKth(root, k, elem);
    cout << elem << endl;    

    k = 7;
    cout << endl << "finding largest element of rank " << k << ": " ;
    findKth(root, k, elem);
    cout << elem << endl;    

}

void test_height_and_balance() {
    cout << endl << "--------" << "test_height_and_balance" << "---------" << endl;
    vector<int> vi {100, 50, 200, 10, 60, 125, 300, 70, 140};
    cout << "creating BST from vector: ";
    for(auto i : vi)
        cout << i << " ";
    cout << endl;
    BSTNode* root = nullptr;
    createBSTAt(root, vi);
    cout <<"doing inorder traversal of bst: " << endl;    
    inorder(root);    

    cout << "getting balance info: " << endl;
    auto bi = getBalanceInfo(root);
    cout << "{height: " << bi.height << ", balanced? " << bi.balance << "} " << endl;
}

void test_symmetry() {
    cout << endl << "--------" << "test_height_and_balance" << "---------" << endl;
    vector<int> vi {100, 50, 200, 10, 60, 125, 300, 70, 140};
    cout << "creating BST from vector: ";
    for(auto i : vi)
        cout << i << " ";
    cout << endl;
    BSTNode* root = nullptr;
    createBSTAt(root, vi);
    cout <<"doing inorder traversal of bst: " << endl;    
    inorder(root);    

    cout << "getting balance info: " << endl;
    auto bi = getBalanceInfo(root);
    cout << "{height: " << bi.height << ", balanced? " << bi.balance << "} " << endl;
}


int main() {
    //bst_test_inorder_traversal();
    //bst_test_findHigherThan();
    //test_find_kth();
    test_height_and_balance();
    return 0;
}