#include "binary_tree.h"
#include <algorithm>

int height(unique_ptr<TreeNode>& root) {
    if (root != nullptr) {
        return max(height(root->left), height(root->right)) + 1;
    }
    return 0;
}
