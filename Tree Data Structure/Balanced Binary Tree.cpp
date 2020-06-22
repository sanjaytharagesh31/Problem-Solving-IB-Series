//O(logN) Space due to recursion
//O(N) Time

int ans;

int solve(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }    
    else {
        int hl = solve(root->left);
        int hr = solve(root->right);
        if(abs(hl-hr)>=2)
            ans = 0;
        return 1+max(hl, hr);
    }
}

int Solution::isBalanced(TreeNode* A) {
    ans = 1;
    int h = solve(A);
    return ans;
}



//O(N) Space
//O(N) Time
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
unordered_map<TreeNode*, int> mp;
int height(TreeNode* root) {
    if(root == NULL) 
        return 0;
    else {
        mp[root] = 1 + max(height(root->left), height(root->right)); 
        return mp[root];
    }
} 

bool solve(TreeNode* root) {
    if(root == NULL)
        return true;
    int dif = mp[root->left] - mp[root->right];
    if(dif >= -1 && dif <=1)
        return true && solve(root->left) && solve(root->right);
    else
        return false;
}


int Solution::isBalanced(TreeNode* A) {
    mp[NULL] = 0;
    int h = height(A);
    return solve(A);
}
