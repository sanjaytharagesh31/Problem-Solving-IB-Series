//Solved without using recusrion

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> s;
    TreeNode* root = A;
    
    while(!s.empty() || root != NULL) {
        while(root != NULL) {
            s.push(root);
            root = root->left;
            continue;
        }
        
        root = s.top();
        s.pop();
        ans.push_back(root->val);
        root = root->right;
    }
    return ans;
}
