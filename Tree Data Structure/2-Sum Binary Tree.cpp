// O(LogN) Space 
// O(N) Time 
//Ultimate Solution

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Iterator {
    private:
        TreeNode* less;
        TreeNode* high;
        stack<TreeNode*> less_s;
        stack<TreeNode*> high_s;
    public:
        Iterator(TreeNode* root) {
            less_s = stack<TreeNode*>();
            high_s = stack<TreeNode*>();
            less = root;
            high = root;
            
            while(less != NULL) {
                less_s.push(less);
                less = less->left;
            }
            
            while(high != NULL) {
                high_s.push(high);
                high = high->right;
            }
        }
        
        int less_next() {
            TreeNode* t = less_s.top();
            less_s.pop();
            TreeNode* cur = t->right;
            while(cur != NULL) {
                less_s.push(cur);
                cur = cur->left;
            }
            return t->val;
        }
        
        bool has_less() {
            return !less_s.empty();
        }
        
        int high_next() {
            TreeNode* t = high_s.top();
            high_s.pop();
            TreeNode* cur = t->left;
            while(cur != NULL) {
                high_s.push(cur);
                cur = cur->right;
            }
            return t->val;
        }
        
        bool has_high() {
            return !high_s.empty();
        }
};

int Solution::t2Sum(TreeNode* A, int B) {
    Iterator obj(A);
    int i = obj.less_next();
    int j = obj.high_next();
    
    while(i < j) {
        if(i + j == B)
            return 1;
        else if(i + j < B && obj.has_less()) {
            i = obj.less_next();
        }
        else if(obj.has_high()){
            j = obj.high_next();
        }
        else {
            return 0;
        }
    }
    return 0;
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
