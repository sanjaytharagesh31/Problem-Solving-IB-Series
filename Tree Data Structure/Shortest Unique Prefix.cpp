struct TrieNode {
    int cnt;
    bool end;
    TrieNode* next[26];
    TrieNode() {
        cnt = 0;
        end = false;
        for(int i=0; i<26; i++) {
            next[i] = NULL;
        }
    }
};

class Trie {
    private:
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }
        
        void insert(string str) {
            TrieNode* cur = root;
            for(int i=0; i<str.length(); i++) {
                if(cur->next[str[i]-'a'] == NULL) {
                    cur->next[str[i]-'a'] = new TrieNode();
                }
                cur = cur->next[str[i]-'a'];
                cur->cnt += 1;
            }
            cur->end = true;
        }
        
        string search(string str) {
            TrieNode* cur = root;
            string tmp = "";
            for(int i=0; i<str.length(); i++) {
                tmp += str[i];
                cur = cur->next[str[i]-'a'];
                if(cur->cnt == 1)
                    return tmp;
            }
            return str;
        }
};

vector<string> Solution::prefix(vector<string> &A) {
    int n = A.size();
    vector<string> ans(n);
    Trie obj;
    for(int i=0; i<n; i++) {
        obj.insert(A[i]);
    }
    for(int i=0; i<n; i++) {
        ans[i] = obj.search(A[i]);
    }
    return ans;
}
