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
 
unordered_set<int> s;

bool solve(TreeNode* root, int k) {
    if(root == NULL)
        return false;
    else if(s.find(k-root->val) != s.end())
        return true;
    else {
        s.insert(root->val);
        return solve(root->left, k) || solve(root->right, k);
    }
}
int Solution::t2Sum(TreeNode* A, int B) {
    s.clear();
    return solve(A, B);
}
