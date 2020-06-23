/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int height(TreeNode* root) {
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int Solution::maxDepth(TreeNode* A) {
    return height(A);
}
