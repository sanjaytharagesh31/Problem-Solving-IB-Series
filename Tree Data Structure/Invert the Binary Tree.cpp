/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* solve(TreeNode* root) {
    if(root == NULL)
        return NULL;
    else {
        TreeNode* l = solve(root->left);
        TreeNode* r = solve(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
}
TreeNode* Solution::invertTree(TreeNode* A) {
    return solve(A);
}
