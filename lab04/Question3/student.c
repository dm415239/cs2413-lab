#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int dfs(struct TreeNode* node, int current) {
    if (node == NULL) return 0;
    current = current * 10 + node->val;
    if (node->left == NULL && node->right == NULL) return current;
    return dfs(node->left, current) + dfs(node->right, current);
}

int sumNumbers(struct TreeNode* root) {
    return dfs(root, 0);
}