/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode *head, *cur;
stack<TreeNode*> s;

BSTIterator::BSTIterator(TreeNode *root) {
    s = stack<TreeNode*>();
    head = root;
    cur = root;
    while(cur != NULL) {
        s.push(cur);
        cur = cur->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !s.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* t = s.top();
    s.pop();
    cur = t->right;
    while(cur != NULL) {
        s.push(cur);
        cur = cur->left;
    }
    return t->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
