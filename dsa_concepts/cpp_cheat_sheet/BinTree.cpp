/*
 * In any recursive binrary tree algo first thing to do is check for NULL for a given node.
*/

#include <iostream>
#include <vector>
#include <algorithm>

template <typename Comparable>
class BinarySearchTree {
    public:
        BinarySearchTree( ) : root {nullptr} {}
        BinarySearchTree(const BinarySearchTree* rhs);
        ~BinarySearchTree( ) { makeEmpty(root); } 
        const Comparable& findMin( );
        const Comparable& findMax( );
        bool isEmpty() {
            return root == nullptr;
        }
        bool contains(const Comparable& value);
        void insert( const Comparable& val );
        bool validateBST(); // check if tree is a BST
        void inorder() {
            inorder(root);
        }
        BinarySearchTree* clone(const BinarySearchTree* orig) {
            if ( this != orig ) {
                makeEmpty();
                this->root = clone(orig->root);
            }

            return *this;
        }

    private:
        struct BinaryNode {            
            Comparable value;
            BinaryNode* left;
            BinaryNode* right;

            BinaryNode(const Comparable& v) : value(v), left(nullptr), right(nullptr) 
            {} 
        };

        bool contains(BinaryNode *node, const Comparable& val);
        void insert(BinaryNode* &node, const Comparable& val);
        bool validateBST(const BinaryNode* node);
        const Comparable& findMin(const BinaryNode* node);
        const Comparable& findMax(const BinaryNode* node);
        
        // traversal routines
        void inorder(const BinaryNode* node);

        void makeEmpty(BinaryNode* node);
        BinarySearchTree<Comparable>::BinaryNode* clone(const BinarySearchTree<Comparable>::BinaryNode* orig)  {
            if ( orig != nullptr ) {
                this->root = new BinaryNode(orig->value, clone(orig->left), clone(orig->right));        
            }       

            return root;
        }


        BinaryNode * root;     
};

template <typename T>
void BinarySearchTree<T>::makeEmpty(BinarySearchTree<T>::BinaryNode* root) {
    if( root != nullptr ) {
        makeEmpty(root->left);
        makeEmpty(root->right);
        delete root;
    }
    return;
}

template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMin() {

    return findMin(root);
}

template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMin(const BinarySearchTree<Comparable>::BinaryNode* node) {

    if ( node == nullptr )
        return nullptr;
    while ( node->left != nullptr )
        node = node->left;

    return node;
}

template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMax() {

    return findMax(root);
}

template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMax(const BinarySearchTree<Comparable>::BinaryNode* node) {

    if ( node == nullptr )
        return nullptr;
    while ( node->right != nullptr )
        node = node->right;

    return node;
}

template <typename Comparable> 
bool BinarySearchTree<Comparable>::contains(const Comparable& val) {
    return contains(root, val);
}

template <typename Comparable> 
bool BinarySearchTree<Comparable>::contains(BinarySearchTree<Comparable>::BinaryNode* node, const Comparable& val) {
    if ( node == nullptr)
        return false;
    else if ( val < node->val )
        return contains(node->left, val);
    else if( node->value < val )
        return contains( node->right, val);

    return true;
}

template <typename Comparable> 
void BinarySearchTree<Comparable>::insert(const Comparable& val) {
    return insert(root, val);
}

template <typename Comparable> 
void BinarySearchTree<Comparable>::insert(BinarySearchTree<Comparable>::BinaryNode* &node, const Comparable& val) {
    if ( node == nullptr)
        node = new BinarySearchTree<Comparable>::BinaryNode(val);
    else if ( val < node->value )
        insert(node->left, val);
    else if( node->value < val )
        insert( node->right, val);
    else
        ; // duplicate

    return;
}

template<typename Comparable>
bool BinarySearchTree<Comparable>::validateBST() {
    if ( root == nullptr )
        return true; // empty tree is BST

    return  validateBST(root);
}

template<typename Comparable>
bool BinarySearchTree<Comparable>::validateBST(const BinarySearchTree<Comparable>::BinaryNode *node) {
    return true;    
}

template <typename Comparable>
void BinarySearchTree<Comparable>::inorder(const BinarySearchTree<Comparable>::BinaryNode * node) {
    if( node != nullptr ) {
        inorder(node->left);
        std::cout << node->value << " ";
        inorder(node->right);
    }

    return;
}


int main() {
    
    #if 0
    BinarySearchTree<int> bst;
    std::vector<int> v {1,2,3,4,5,6,7};

    for(const auto& x : v)
       bst.insert(x);
    #endif
    
    #if 0
    BinarySearchTree<int> bst;
    std::vector<float> v {4.2, 5, 6, 4.1, 2, 2.9, -1};

    for(const auto& x : v)
       bst.insert(x);
    #endif

    #if 1
    BinarySearchTree<float> bst;
    std::vector<float> v {4.2, 5, 6, 4.1, 2, 2.9, -1};

    for(const auto& x : v)
       bst.insert(x);
    #endif

    
    bst.inorder();

    return 0;
} 