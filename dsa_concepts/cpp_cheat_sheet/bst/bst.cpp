#include <iostream>
#include <memory>
#include <vector>
#include <queue>

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


void level_order(const unique_ptr<TreeNode>& root, vector<int>& vi) {    
    if (root!=nullptr) {
    queue<TreeNode*> q;
	q.push(root.get());

	while(!q.empty()) {
		auto front = q.front();
		q.pop();
		if(front->left!=nullptr)
			q.push(front->left.get());
		if(front->right!=nullptr)
			q.push(front->right.get());
		vi.push_back(front->val);
	}
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

int height(const unique_ptr<TreeNode>& root) {
    if(root)
        return max(height(root->left), height(root->right)) + 1;
    return -1;
}

bool balanced(const unique_ptr<TreeNode>& root) {
	if(root && balanced(root->left) && balanced(root->right) && abs(height(root->left) - height(root->right))<=1)
		return true;
	else if(!root)
		return true;

	return false;
}

pair<int, bool> heightAndBalance(const unique_ptr<TreeNode>& root) {
	if(!root) 
		return {-1, true};
	auto pl = heightAndBalance(root->left);
	auto pr = heightAndBalance(root->right);

	return {max(pl.first, pr.first)+1, pl.second && pr.second && abs(pl.first - pr.first)<=1};
		
}

void remove(int x, unique_ptr<TreeNode>& root){
    if(root) {
        if(x < root->val)
            remove(x, root->left);
        else if(root->val < x)
            remove(x, root->right);
        else if(root->left && root->right) {
		TreeNode* p = root.get();
		TreeNode* r = p->right.get();
        bool isLeft = false;
		while(r->left) {
            isLeft = true;
			p = r;
			r = r->left.get();
		}
		root->val = r->val;
        if(isLeft)
            p->left.reset(nullptr);
        else
            p->right.reset(nullptr); 
        } else {
		auto x = (root->left? root->left : root->right).get();
        root->val = x->val;
        root->right.reset(x->right.get());
        root->left.reset(x->left.get());        
        }
    } 
}

unique_ptr<TreeNode>& findMax1(unique_ptr<TreeNode>& root) {
    unique_ptr<TreeNode>* ptr = &root;
    while(*ptr && (*ptr)->right)
        ptr = &((*ptr)->right);
    return *ptr;    
}

ostream& operator<<(ostream& os, const vector<int>& vi) {
    for(auto i:vi)
        os << i << " ";
    return os;
}

ostream& operator<<(ostream& os, const unique_ptr<TreeNode>& root) {
    vector<int> vi;
    cout << "Tree height: " << height(root) << endl;
    cout << "balanced? " << (balanced(root)? "yes" : "no")  << endl;
    auto p = heightAndBalance(root);
    cout << "heightAndBalance: <" << p.first << ", " << p.second << ">" << endl;
    inorder(root, vi);   
    os << "\tinorder: " << vi << endl;
    vi.erase(vi.begin(), vi.end());

    preorder(root, vi);   
    os << "\tpreorder: " << vi << endl;
    vi.erase(vi.begin(), vi.end());

    postorder(root, vi);   
    os << "\tpostorder: " << vi << endl;
    vi.erase(vi.begin(), vi.end());

    level_order(root, vi);   
    os << "\tlevel order: " << vi << endl;
    vi.erase(vi.begin(), vi.end());

    return os;
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

    cout <<"removing 10: " << endl;
    remove(10, root);
    cout <<root;


    return 0;
}
