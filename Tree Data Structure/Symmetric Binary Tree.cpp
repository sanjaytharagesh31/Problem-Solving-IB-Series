/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool solve(TreeNode* a, TreeNode* b) {
    if(a == NULL && b == NULL) 
        return true;
    else if(a == NULL || b == NULL)
        return false;
    else if(a->val == b->val){
        return solve(a->left, b->right) && solve(a->right, b->left);
    }
    else {
        return false;
    }
}
int Solution::isSymmetric(TreeNode* A) {
    return solve(A, A);
}
