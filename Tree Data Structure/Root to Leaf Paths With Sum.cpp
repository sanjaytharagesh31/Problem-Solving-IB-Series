/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

typedef vector<vector<int>> vv;
vv ans;

void solve(TreeNode* root, int sum, vector<int> arr) {
    if(root == NULL)
        return;
    else if(root->left == NULL && root->right == NULL) {
        if(sum == root->val) {
            arr.push_back(root->val);
            ans.push_back(arr);
        }
    }
    else {
        arr.push_back(root->val);
        solve(root->left, sum-root->val, arr);
        solve(root->right, sum-root->val, arr);
    }
}
vector<vector<int>> Solution::pathSum(TreeNode* A, int B) {
    ans = vv();
    vector<int> arr;
    solve(A, B, arr);
    return ans;
}
