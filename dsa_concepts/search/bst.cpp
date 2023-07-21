#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <memory>

using namespace std;

struct BSTNode {
    static int node_count;
    int val;
    unique_ptr<BSTNode> left, right;
    BSTNode(int v=0) : val{v} {
        ++node_count;
        //cout << "creating bstnode # " << ++node_count << endl; 
        }
    ~BSTNode() {
        cout << "deleting bstnode # " << node_count-- << endl; 
        }
};

int BSTNode::node_count = 0;

using NodePtrType = unique_ptr<BSTNode>;

void insert(int v, NodePtrType& root) {
    if(root == nullptr) 
        root  = make_unique<BSTNode>(v);
    else if(v < root->val)
        insert(v, root->left);
    else if(root->val < v)
        insert(v, root->right);
    else    
        ;
}

void remove(int val, NodePtrType& root) {
    if (root) {
        if(val < root->val)
            remove(val, root->left);
        else if(root->val < val)
            remove(val, root->right);
        else {
            if(root->left && root->right) {
                auto p = root.get();
                auto to_delete = (root->right).get();
                while(to_delete && (to_delete->left).get()) {
                    p = to_delete;
                    to_delete = (p->left).get();                        
                }
                root->val = p->left->val;
                p->left = nullptr;              
            } else {
                NodePtrType& x = root->left? root->left : root->right;                
                //root->val = x->val;
                //x.reset();
                root = move(x);
            }
        }
    }
}

void make_empty(NodePtrType& root) {
    root.reset();
}

void createBSTAt(NodePtrType& root, const vector<int>& vi) {  
    for(auto i: vi) {
        insert(i, root);
    }
}

NodePtrType createBST(const vector<int>& vi) {
    NodePtrType root {};
    createBSTAt(root, vi);
    return root;
}

const NodePtrType& search(int target, const NodePtrType& root) {
    if(!root)
        return root;
    if(root->val == target)
        return root;
    return target < root->val ? search(target, root->left) : search(target, root->right);
}

void inorder(const NodePtrType& root) {
    if (root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

// struct HigherThanStatus {
//     int value;
//     bool found;
//     HigherThanStatus() : value {numeric_limits<int>::min()}, found {false} {}
// };

int findHigherThan_Helper(const int target, const NodePtrType& root, int& status) {
    if (root) {
        if(target <= root->val) {
            status = root->val;
            return findHigherThan_Helper(target, root->left, status);
        } else if(root->val < target) {
            return findHigherThan_Helper(target, root->right, status);
        }
    }
    return status;
}

int findHigherThan(const int v, const NodePtrType& root) {
    int status = numeric_limits<int>::min();
    findHigherThan_Helper(v, root, status);
    return status;
}

void findKth(const NodePtrType& root, int& k, int& kth) {
    if(root && k) {
        findKth(root->right, k, kth);
        if(--k==0) {
            kth = root->val;
            return;
        }
        findKth(root->left, k, kth);
    }    
}

int height(NodePtrType& root) {
    if(root==nullptr) 
        return 0;
    return max(height(root->left), height(root->right)) + 1;    
}

struct HeightAndBalance {
    int height;
    bool balance;
    HeightAndBalance(int h, bool b) : height {h}, balance {b} {}
};

HeightAndBalance getBalanceInfo(NodePtrType& root) {
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
    NodePtrType root = nullptr;
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
    NodePtrType root = nullptr;
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
    NodePtrType root = nullptr;
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
    NodePtrType root = nullptr;
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
    NodePtrType root = nullptr;
    createBSTAt(root, vi);
    cout <<"doing inorder traversal of bst: " << endl;    
    inorder(root);    

    cout << "getting balance info: " << endl;
    auto bi = getBalanceInfo(root);
    cout << "{height: " << bi.height << ", balanced? " << bi.balance << "} " << endl;
}

void test_search() {
    NodePtrType root = createBST({100, 9, 200, 90, 7, 210, 190});
    cout << "given tree: ";
    inorder(root);
    cout << endl;
    auto val = 10;
    cout << "contains " << val <<"? " << (search(val, root) ? "yes" : "no") << endl;

    val = 210;
    cout << "contains " << val <<"? " << (search(val, root) ? "yes" : "no") << endl;    

    val = 211;
    cout << "contains " << val <<"? " << (search(val, root) ? "yes" : "no") << endl;    

}

void test_find_higher_than_helper(vector<int> vi, int val) {
    NodePtrType root = createBST(vi);
    cout << "given tree:";
    inorder(root);
    cout << ", first node higher than " << val << " is: " << findHigherThan(val, root) << endl;
}

void test_findHigherThan() {
    test_find_higher_than_helper({100, 50, 150, 20, 60, 115, 200, 300, 400}, 155);
    //test_find_higher_than_helper({100, 50, 150, 20, 60, 115, 200, 300, 400}, 75);
    //test_find_higher_than_helper({100, 50, 150, 20, 60, 115, 200, 300, 400}, -1);
    //test_find_higher_than_helper({100, 50, 150, 20, 60, 115, 200, 300, 400}, 500);            
}

void test_remove_helper(vector<int> vi, int val) {
    cout << endl << endl;
    NodePtrType root = createBST(vi);
    cout << "given tree:";
    inorder(root);
    cout << endl << "now deleting: " << val << endl;
    remove(val, root);
    cout << "modified bst: " << endl;
    inorder(root);
}

void test_remove() {
    test_remove_helper({100, 50, 150, 20, 60, 115, 200, 300, 400}, 155);
    test_remove_helper({100, 50, 150, 20, 60, 115, 200, 300, 400}, 150);
}

void test_make_empty_helper(vector<int> vi) {
    NodePtrType root = createBST(vi);
    cout << "given tree:";
    inorder(root);
    make_empty(root);
    cout << "after make_empty, the tree becones:";
    inorder(root);
    cout <<endl<< "thatz it" << endl;
}

void test_make_empty() {
    test_make_empty_helper({100, 50, 150, 20, 60, 115, 200, 300, 400});
    test_make_empty_helper({100, 50, 150, 20, 60});

}


int main() {
    //bst_test_inorder_traversal();
    //bst_test_findHigherThan();
    //test_find_kth();
    //test_height_and_balance();
    //test_search();
    //test_findHigherThan();
    //test_remove();
    test_make_empty();
    return 0;
}