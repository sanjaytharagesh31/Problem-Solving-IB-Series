/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int ans;
 map<TreeNode*, int> mp;
 
 int solve(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    else if(mp.find(root) != mp.end()) {
        return mp[root];
    }
    else {
        int l = solve(root->left);
        int r = solve(root->right);
        vector<int> temp{root->val, root->val+l, root->val+r, l+r+root->val};
        ans = max(ans, *max_element(temp.begin(), temp.end()));
        mp[root] = root->val + max(0, max(l, r));
        return root->val + max(0, max(l, r));
    }
}

int Solution::maxPathSum(TreeNode* A) {
    ans = INT_MIN;
    mp = map<TreeNode*, int>();
    solve(A);
    return ans;
}
