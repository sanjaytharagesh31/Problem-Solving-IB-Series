/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    TreeNode* root = A;
    stack<TreeNode*> s;
    while(!s.empty() || root != NULL) {
        while(root != NULL) {
            ans.push_back(root->val);
            s.push(root);
            root = root->left;
        }
        TreeNode* t = s.top();
        s.pop();
        root = t->right;
    }
    return ans;
}
