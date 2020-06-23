//O(N) Space 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> ans;
void solve(TreeNode* root, int cnt) {
    if(root != NULL) {
        solve(root->left, cnt+1);
        ans.push_back(root->val);
        solve(root->right, cnt+1);
    }    
}

int Solution::kthsmallest(TreeNode* A, int B) {
    ans.clear();
    solve(A, 0);
    return ans[B-1];
}


//O(1) Space
int k;
int cnt;
int ans;

void solve(TreeNode* root) {
    if(root != NULL) {
        solve(root->left);
        if(cnt == k)
            ans = root->val;
        cnt++;
        solve(root->right);
    }
}

int Solution::kthsmallest(TreeNode* A, int B) {
    k = B;
    cnt = 1;
    solve(A);
    return ans;
}
