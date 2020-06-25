/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(A);
    bool flag = false;
    
    while(!q.empty()) {
        int sz = q.size();
        vector<int> tmp(sz);
        for(int i=0; i<sz; i++) {
            tmp[i] = q.front()->val;
            if(q.front()->left != NULL)
                q.push(q.front()->left);
            if(q.front()->right != NULL)
                q.push(q.front()->right);
            q.pop();
        }
        if(flag == true)
            reverse(tmp.begin(), tmp.end());
        flag = !flag;
        ans.push_back(tmp);
    }
    return ans;
}
