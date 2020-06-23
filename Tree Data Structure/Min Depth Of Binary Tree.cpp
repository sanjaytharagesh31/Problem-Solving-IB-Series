/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    TreeNode* root = A;
    queue<TreeNode*> q;
    q.push(root);
    int depth = 1;
    while(!q.empty()) {
        int sz = q.size();
        for(int i=0; i<sz; i++) {
            TreeNode* t = q.front();
            q.pop();
            if(t->left == NULL && t->right == NULL)
                return depth;
            else {
                if(t->left != NULL)
                    q.push(t->left);
                if(t->right != NULL)
                    q.push(t->right);
            }
        }
        depth++;
    }
    return 0;
}
