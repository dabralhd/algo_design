#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* right;
        TreeNode* left;
        TreeNode(int d, TreeNode* r, TreeNode* l) : data { d }, right { r }, left { l }
        {}

        TreeNode(const int& d) : TreeNode( d, nullptr, nullptr )
        {}

        TreeNode() : TreeNode( 0, nullptr, nullptr )
        {}
};

TreeNode* makeTree() {
        TreeNode *root = new TreeNode(12);
        TreeNode *l11 = new TreeNode(10);
        TreeNode *l12 = new TreeNode(9);

        TreeNode *l21 = new TreeNode(31);
        TreeNode *l22 = new TreeNode(4);
        TreeNode *l23 = new TreeNode(7);

        TreeNode *l31 = new TreeNode(21);
        TreeNode *l32 = new TreeNode(22);

        root->left = l11;
        root->right = l12;

        l11->left = l21;
        // null

        l12->left = l22;
        l12->right = l23;

        l21->right = l31;
        l23->left = l32;

        return root;
}

void inorder(TreeNode* r) {
    if ( r != nullptr ) {
        inorder( r->left );
        cout << r->data << " ";
        inorder( r->right );
    }
    return;
}

void preorder(TreeNode* r) {
    if ( r != nullptr ) {        
        cout << r->data << " ";
        preorder( r->left );
        preorder( r->right );
    }
    return;
}

void postorder(TreeNode* r) {
    if ( r != nullptr ) {  
        postorder( r->left );
        postorder( r->right );
        cout << r->data << " ";
    }
    return;
}

int height(TreeNode* r) {
   if (r != nullptr ) {
        return max ( height(r->left), height(r->right) ) + 1;
    }
    return -1;
} 

struct StatusHeightWithBalance {
    int height;
    bool balanced;
    static int highest_balanced;
    StatusHeightWithBalance() : height { -1 }, balanced { true }
    {}
};

int StatusHeightWithBalance::highest_balanced = -1;

const StatusHeightWithBalance& heightAndBalance(TreeNode* root ) {
    StatusHeightWithBalance *status = new StatusHeightWithBalance();
    if( root != nullptr ) {
        StatusHeightWithBalance left = heightAndBalance(root->left);
        StatusHeightWithBalance right = heightAndBalance(root->right);
        status->balanced = left.balanced && right.balanced && (abs( left.height - right.height ) <= 1);
        status->height = max(left.height, right.height) + 1;
        status->highest_balanced = (status->balanced && status->height>status->highest_balanced)? status->height : status->highest_balanced;
        return *status;
    }
    return *status;
}

void levelOrder(TreeNode* root) {
    queue<TreeNode*> q;

    q.push(root);
    while( !q.empty() ) {
        TreeNode* node = q.front();
        q.pop();

        if( node!=nullptr ) {
            cout << node->data << " ";
            if( node->left!=nullptr ) q.push(node->left);
            if( node->right!=nullptr ) q.push(node->right);
        }
    }
}

/*
const StatusDepthWithBalance& depthAndBalance(TreeNode* root) {
    if( root!=nullptr ) {
        int h_left = height(root->left);
        int r_left = height(root->right);
    }
}
*/

int main() {
        TreeNode *root = new TreeNode(12);
        TreeNode *l11 = new TreeNode(10);
        TreeNode *l12 = new TreeNode(9);

        TreeNode *l21 = new TreeNode(31);
        TreeNode *l22 = new TreeNode(4);
        TreeNode *l23 = new TreeNode(7);

        TreeNode *l31 = new TreeNode(7);
        TreeNode *l32 = new TreeNode(21);
        TreeNode *l33 = new TreeNode(22);

        root->left = l11;
        root->right = l12;

        l11->left = l21;
        // null

        l12->left = l22;
        l12->right = l23;

        //l21->left = l31;
        l21->right = l32;
        //l23->left = l33;

        cout << "inorder: ";
        inorder(root);
        cout << endl;

        cout << "preorder: ";
        preorder(root);
        cout << endl;

        cout << "postorder: ";
        postorder(root);
        cout << endl;

        cout << "height: " << heightAndBalance(root).height << endl;

        cout << "balanced?: " << heightAndBalance(root).balanced << endl;

        cout << "highest_balanced: " << heightAndBalance(root).highest_balanced << endl;

        cout << "levelOrder: ";
        levelOrder(root);
        cout << endl;

        return 0;
}