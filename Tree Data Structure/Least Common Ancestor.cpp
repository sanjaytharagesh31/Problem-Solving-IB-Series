/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
bool find(TreeNode* root, int val) {
    if(root == NULL)
        return false;
    else if(root->val == val)
        return true;
    else 
        return find(root->left, val) || find(root->right, val);
}

TreeNode* solve(TreeNode* root, int a, int b) {
    if(root == NULL)
        return NULL;
    else if(root->val == a) {
        return root;
    }
    else if(root->val == b) {
        return root;
    }
    else {
        TreeNode* l = solve(root->left, a, b);
        TreeNode* r = solve(root->right, a, b);
        if(l != NULL && r != NULL)
            return root;
        else if(l != NULL && r == NULL)
            return l;
        else
            return r;
    }
}
int Solution::lca(TreeNode* A, int B, int C) {
    if(!find(A, B) || !find(A, C))
        return -1;
    return solve(A, B, C)->val;
    
}
