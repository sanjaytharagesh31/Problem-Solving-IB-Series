/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool solve(TreeNode* root, int sum) {
    if(root == NULL)
        return sum == 0;
    else if(root->left == NULL && root->right == NULL)
        return sum==root->val;
    else {
        int diff = sum - root->val;
        bool l = false;
        bool r = false;
        if(root->left != NULL)
            l = solve(root->left, diff);
        if(root->right != NULL)
            r = solve(root->right, diff);
        return l || r;
    }
}
int Solution::hasPathSum(TreeNode* A, int B) {
    return solve(A, B);
}
