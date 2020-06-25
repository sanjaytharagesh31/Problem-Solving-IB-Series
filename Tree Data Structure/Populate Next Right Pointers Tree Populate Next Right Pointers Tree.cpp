/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*> q;
    q.push(A);
    while(!q.empty()) {
        int sz = q.size();
        TreeLinkNode* pre = NULL;
        for(int i=0; i<sz; i++) {
            if(pre != NULL)
                pre->next = q.front();
            pre = q.front();
            if(q.front()->left != NULL)
                q.push(q.front()->left);
            if(q.front()->right != NULL)    
                q.push(q.front()->right);
            q.pop();
        }
    }
}
