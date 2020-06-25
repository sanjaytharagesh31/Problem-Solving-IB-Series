struct TrieNode {
    bool end;
    TrieNode* next[26];
    TrieNode() {
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
                if(cur->next[str[i]-'a'] != NULL)
                    cur = cur->next[str[i]-'a'];
                else {
                    cur->next[str[i]-'a'] = new TrieNode();
                    cur = cur->next[str[i]-'a'];
                }
            }
            cur->end = true;
        }
        
        bool search(string str) {
            TrieNode* cur = root;
            for(int i=0; i<str.length(); i++) {
                if(cur->next[str[i]-'a'] == NULL)
                    return false;
                cur = cur->next[str[i]-'a'];
            }
            return cur->end;
        }
};

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

void merge(vector<pair<int, int>> &v, int i, int m, int j) {
    vector<pair<int, int>> tmp;
    int x = i;
    int y = m+1;
    while(x<=m && y<=j) {
        if(v[x].first >= v[y].first) {
            tmp.push_back(make_pair(v[x].first, v[x].second));
            x++;
        }
        else {
            tmp.push_back(make_pair(v[y].first, v[y].second));
            y++;
        }
    }
    while(x<=m) {
        tmp.push_back(make_pair(v[x].first, v[x].second));
        x++;
    }
    while(y<=j) {
        tmp.push_back(make_pair(v[y].first, v[y].second));
        y++;
    }
    int ind = 0;
    for(int p=i; p<=j; p++)
        v[p] = tmp[ind++];
}

void merge_sort(vector<pair<int, int>> &v, int i, int j) {
    if(i < j) {
        int m = i+(j-i)/2;
        // int m = (i+j)/2;
        merge_sort(v, i, m);
        merge_sort(v, m+1, j);
        merge(v, i, m, j);
    }
}

vector<int> Solution::solve(string A, vector<string> &B) {
    int n = B.size();
    vector<pair<int, int>> v(n);
    Trie obj;
    string tmp = "";
    for(int i=0; i<A.length(); i++) {
        if(A[i] != '_')
            tmp += A[i];
        if(A[i] == '_' || i == A.length()-1) {
            // cout << "Inserting : " << tmp << endl;
            obj.insert(tmp);
            tmp = "";
        }
    }
    
    for(int i=0; i<n; i++) {
        string r = B[i];
        string tmp = "";
        v[i].first = 0;
        v[i].second = i;
        for(int j=0; j<r.length(); j++) {
            if(r[j] != '_')
                tmp += r[j];
            if(r[j] == '_' || j == r.length()-1) {
                // cout << "Searching : " << tmp << endl;
                if(obj.search(tmp)) {
                    v[i].first++;
                }
                tmp = "";
            }
        }
    }
    merge_sort(v, 0, n-1);
    vector<int> ans(n);
    for(int i=0; i<n; i++) {
        // cout << v[i].first << " " << v[i].second << endl;
        ans[i] = v[i].second;
    }
    return ans;
}
