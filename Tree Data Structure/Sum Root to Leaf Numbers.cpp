/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int mod = 1003;
int ans;

void solve(TreeNode* root, int sum) {
    if(root == NULL)
        return;
    else if(root->left == NULL && root->right == NULL) {
        ans += (sum * 10 + root->val)%mod;
    }
    else {
        solve(root->left, (sum*10+root->val)%mod);
        solve(root->right, (sum*10+root->val)%mod);
    }
}

int Solution::sumNumbers(TreeNode* A) {
    ans = 0;
    solve(A, 0);
    return ans%mod;
}
