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
    else if(a != NULL && b != NULL) {
        if(a->val != b->val)
            return false;
        else
            return solve(a->left, b->left) && solve(a->right, b->right);
    }
    else {
        return false;
    }
}
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    return solve(A, B);
}
