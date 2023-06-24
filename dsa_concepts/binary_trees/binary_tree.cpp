#include <iostream>
#include <typeinfo>
#include <queue>

using namespace std;

struct BinTreeNode {
    char val;
    BinTreeNode *left, *right;
    BinTreeNode(char v) : val {v}, left{nullptr}, right{nullptr}
    {}
 };

void tree_traversal_test_1();
void inorder(BinTreeNode* root);
void preorder(BinTreeNode* root);
void postorder(BinTreeNode* root);
vector<vector<char>> level_order1(BinTreeNode* root);
void level_order(BinTreeNode* root);
bool checkSymmetry(BinTreeNode* left, BinTreeNode* right);
bool isSymmetric(BinTreeNode* root);
void test_Symmetry_2();
void test_Symmetry1();
BinTreeNode* leastCommonAncestor(BinTreeNode* first, BinTreeNode* second);
void test_least_common_ancestor();
int sum_of_leave_paths(BinTreeNode* root);
void test_sum_of_leave_paths();

int main() {
    int* x, y;
    cout << typeid(x).name() << " " << typeid(y).name() << endl;
    //tree_traversal_test_1();
    //test_Symmetry_1();
    //test_Symmetry_2();
    //test_least_common_ancestor();
    test_sum_of_leave_paths();

    return 0;
}

void inorder(BinTreeNode* root) {
    if(root) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void preorder(BinTreeNode* root) {
    if(root) {
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BinTreeNode* root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }
}

void level_order(BinTreeNode* root) {
    queue<BinTreeNode*> q;
    if(root)
        q.push(root);

    while(!q.empty()) {
        auto& u = q.front();
        q.pop();
        if(u) {
            cout << u->val << " ";
            if(u->left)
                q.push(u->left);
            if(u->right)
                q.push(u->right);
        }
    }
    cout << endl;
}

vector<vector<char>> level_order1(BinTreeNode* root) {
    queue<BinTreeNode*> q;
    vector<vector<char>> ans;
    if(root)
        q.push(root);

    while(!q.empty()) {
        int sz = q.size();
        vector<char> vch;
        while(sz) {
            auto u = q.front();
            vch.push_back(u->val);
            q.pop();
            sz--;
            if(u) {
                if(u->left)
                    q.push(u->left);
                if(u->right)
                    q.push(u->right);
            }
        }
        ans.push_back(vch);
    }
    return ans;
}

bool checkSymmetry(BinTreeNode* left, BinTreeNode* right) {
    if(left==nullptr && right==nullptr) 
        return true;
    else if(left!=nullptr && right!=nullptr && left->val==right->val 
    && checkSymmetry(left->left, right->right)
    && checkSymmetry(left->right, right->left))
        return true;
    return false;
}

bool isSymmetric(BinTreeNode* root) {
    if(!root) 
        return true;
    return checkSymmetry(root->left, root->right);
}

void tree_traversal_test_1() {
    BinTreeNode *a = new BinTreeNode('A');
    BinTreeNode *b = new BinTreeNode('B');
    BinTreeNode *c = new BinTreeNode('C');
    BinTreeNode *d = new BinTreeNode('D');
    BinTreeNode *e = new BinTreeNode('E');
    BinTreeNode *f = new BinTreeNode('F');
    BinTreeNode *g = new BinTreeNode('G');
    BinTreeNode *h = new BinTreeNode('H');
    BinTreeNode *i = new BinTreeNode('I');
    BinTreeNode *j = new BinTreeNode('J');
    BinTreeNode *k = new BinTreeNode('K');
    BinTreeNode *l = new BinTreeNode('L');
    BinTreeNode *m = new BinTreeNode('M');
    BinTreeNode *n = new BinTreeNode('N');
    BinTreeNode *o = new BinTreeNode('O');
    BinTreeNode *p = new BinTreeNode('P');

    a->left = b;
    a->right = i;
    b->left = c;
    b->right = f;
    c->left = d;
    c->right = e;
    f->right= g;
    g->left = h;
    i->left = j;
    j->right = k;
    k->left = l;
    k->right = n;
    l->right = m;
    i->right = o;
    o->right = p;

    cout << "inorder traversal: ";
    inorder(a); 
    cout << endl;

    cout << "preorder traversal: ";
    preorder(a); 
    cout << endl;

    cout << "postorder traversal: ";
    postorder(a);
    cout << endl;

    cout << "level order traversal: ";
    level_order(a);
    cout << endl;

    cout << "level_order with vector2d return" << endl;
    vector<vector<char>> lo = level_order1(a);
    for(auto i=0; i<lo.size(); i++) {
        auto vch = lo[i];
        for(char ch : vch) {
            cout << ch << " ";
        }
        cout << endl;
    }
 }

void test_Symmetry_1() {
    BinTreeNode *a = new BinTreeNode('A');
    BinTreeNode *b = new BinTreeNode('B');
    BinTreeNode *e = new BinTreeNode('B');
    BinTreeNode *c = new BinTreeNode('C');
    BinTreeNode *f = new BinTreeNode('C');
    BinTreeNode *d = new BinTreeNode('D');
    BinTreeNode *g = new BinTreeNode('D');

    a->left = b;
    a->right = e;
    b->right = c;
    e->left = f;
    c->right = d;
    f->left = g;

    cout << "inorder traversal: ";
    inorder(a); 
    cout << endl;

    cout << "level order traversal: ";
    level_order(a);
    cout << endl;

    cout << "level_order with vector2d return" << endl;
    vector<vector<char>> lo = level_order1(a);
    for(auto i=0; i<lo.size(); i++) {
        auto vch = lo[i];
        for(char ch : vch) {
            cout << ch << " ";
        }
        cout << endl;
    }

    cout << "is symmnetry: " << isSymmetric(a) << endl;

 }

void test_Symmetry_2() {
    BinTreeNode *a = new BinTreeNode('A');
    BinTreeNode *b = new BinTreeNode('B');
    BinTreeNode *e = new BinTreeNode('B');
    BinTreeNode *c = new BinTreeNode('C');
    BinTreeNode *f = new BinTreeNode('C');
    BinTreeNode *d = new BinTreeNode('D');
    BinTreeNode *g = new BinTreeNode('D');
    BinTreeNode *extra = new BinTreeNode('Z');

    a->left = b;
    a->right = e;
    b->right = c;
    e->left = f;
    c->right = d;
    f->left = g;
    g->left = extra;

    cout << "inorder traversal: ";
    inorder(a); 
    cout << endl;

    cout << "level order traversal: ";
    level_order(a);
    cout << endl;

    cout << "level_order with vector2d return" << endl;
    vector<vector<char>> lo = level_order1(a);
    for(auto i=0; i<lo.size(); i++) {
        auto vch = lo[i];
        for(char ch : vch) {
            cout << ch << " ";
        }
        cout << endl;
    }

    cout << "is symmnetry: " << isSymmetric(a) << endl;

 }

struct NodesFound {
    BinTreeNode* root;
    int count;
    NodesFound() : count {0}, root{nullptr} {}
    NodesFound(int c, BinTreeNode* node) : count {c}, root{node} {}    
};

NodesFound lca_search(BinTreeNode* root, BinTreeNode* first, BinTreeNode* second) {
    // postorder traversal
    if(!root)
        return {};

    auto lresult = lca_search(root->left, first, second);
    if(lresult.count==2) 
        return lresult;

    auto rresult = lca_search(root->right, first, second);
    if(rresult.count==2)
        return rresult;

    int total_found = lresult.count + rresult.count + (root==first) + (root==second);
    return NodesFound {total_found, total_found==2? root: nullptr};
}

BinTreeNode* leastCommonAncestor(BinTreeNode* root, BinTreeNode* first, BinTreeNode* second) {
   return lca_search(root, first, second).root;
}

void sum_of_leave_paths_helper(BinTreeNode* root, int num, int& sum) {
    if(root) {
        num = num<<1 | (root->val - '0');
        if(root->left==nullptr && root->right==nullptr) {  // reached a leaf
            sum += num;
            num >>= 1;
        }
         
        sum_of_leave_paths_helper(root->left, num, sum);
        sum_of_leave_paths_helper(root->right, num, sum);
    }
}

int sum_of_leave_paths(BinTreeNode* root) {
    int sum = 0;
    int num = 0;
    sum_of_leave_paths_helper(root, num, sum);   
    return sum;
}

void test_least_common_ancestor() {
    BinTreeNode *a = new BinTreeNode('A');
    BinTreeNode *b = new BinTreeNode('B');
    BinTreeNode *c = new BinTreeNode('C');
    BinTreeNode *d = new BinTreeNode('D');
    BinTreeNode *e = new BinTreeNode('E');
    BinTreeNode *f = new BinTreeNode('F');
    BinTreeNode *g = new BinTreeNode('G');
    BinTreeNode *h = new BinTreeNode('H');
    BinTreeNode *i = new BinTreeNode('I');
    BinTreeNode *j = new BinTreeNode('J');
    BinTreeNode *k = new BinTreeNode('K');
    BinTreeNode *l = new BinTreeNode('L');
    BinTreeNode *m = new BinTreeNode('M');
    BinTreeNode *n = new BinTreeNode('N');
    BinTreeNode *o = new BinTreeNode('O');
    BinTreeNode *p = new BinTreeNode('P');

    a->left = b;
    a->right = i;
    b->left = c;
    b->right = f;
    c->left = d;
    c->right = e;
    f->right= g;
    g->left = h;
    i->left = j;
    j->right = k;
    k->left = l;
    k->right = n;
    l->right = m;
    i->right = o;
    o->right = p;

    cout << "inorder traversal: ";
    inorder(a); 
    cout << endl;

    cout << "level order traversal: ";
    level_order(a);
    cout << endl;

    cout << "level_order with vector2d return" << endl;
    vector<vector<char>> lo = level_order1(a);
    for(auto i=0; i<lo.size(); i++) {
        auto vch = lo[i];
        for(char ch : vch) {
            cout << ch << " ";
        }
        cout << endl;
    }

    cout << "finding LCA of node c and g: " << leastCommonAncestor(a, c, g)->val << endl;
    cout << "finding LCA of node b andm: " << leastCommonAncestor(a, b, m)->val << endl;
    cout << "*finding LCA of node l and m: " << leastCommonAncestor(a, l, m)->val << endl;
    cout << "finding LCA of node p and l: " << leastCommonAncestor(a, p, l)->val << endl;

}

void test_sum_of_leave_paths() {
    cout << "--------" << "test_sum_of_leave_paths" << "-----------" << endl;
    BinTreeNode *a = new BinTreeNode('1');
    BinTreeNode *b = new BinTreeNode('0');
    BinTreeNode *c = new BinTreeNode('0');
    BinTreeNode *d = new BinTreeNode('0');
    BinTreeNode *e = new BinTreeNode('1');
    BinTreeNode *f = new BinTreeNode('1');
    BinTreeNode *g = new BinTreeNode('1');
    BinTreeNode *h = new BinTreeNode('0');
    BinTreeNode *i = new BinTreeNode('1');
    BinTreeNode *j = new BinTreeNode('0');
    BinTreeNode *k = new BinTreeNode('0');
    BinTreeNode *l = new BinTreeNode('1');
    BinTreeNode *m = new BinTreeNode('1');
    BinTreeNode *n = new BinTreeNode('0');
    BinTreeNode *o = new BinTreeNode('0');
    BinTreeNode *p = new BinTreeNode('0');

    a->left = b;
    a->right = i;
    b->left = c;
    b->right = f;
    c->left = d;
    c->right = e;
    f->right= g;
    g->left = h;
    i->left = j;
    j->right = k;
    k->left = l;
    k->right = n;
    l->right = m;
    i->right = o;
    o->right = p;

    cout << "inorder traversal: ";
    inorder(a); 
    cout << endl;

    cout << "level order traversal: ";
    level_order(a);
    cout << endl;

    cout << "level_order with vector2d return" << endl;
    vector<vector<char>> lo = level_order1(a);
    for(auto i=0; i<lo.size(); i++) {
        auto vch = lo[i];
        for(char ch : vch) {
            cout << ch << " ";
        }
        cout << endl;
    }

    cout << "sum of leave paths: " << sum_of_leave_paths(a) << endl;

}




