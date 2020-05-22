//A simpler solution

bool comp(int a, int b) {
    string str1 = to_string(a) + to_string(b);
    string str2 = to_string(b) + to_string(a);
    return str1>=str2;
}

string Solution::largestNumber(const vector<int> &A) {
    vector<int> tmp(A);
    string ans = "";
    bool flag = false;
    sort(tmp.begin(), tmp.end(), comp);
    for(int x : tmp){
        if(x != 0 || flag == true) {
            flag = true;
            ans += to_string(x);
        }
    }
    if(flag == false)
        return "0";
    return ans;


bool comp(int a, int b) {
    string str1 = to_string(a) + to_string(b);
    string str2 = to_string(b) + to_string(a);
    return str1>=str2;
}

string Solution::largestNumber(const vector<int> &A) {
    map<int, vector<int>> mp;
    int n = A.size();
    string ans = "";
    for(int i=0; i<n; i++ ){
        if(A[i] == 0)
            mp[0].push_back(0);
        else
            mp[A[i]/(pow(10, floor(log10(A[i])) ))].push_back(A[i]);
    }
    if(mp.size() == 1 && mp[0].size() > 0)
        return "0";
    for(int i=9; i>=0; i--) {
        if(mp.find(i) == mp.end())
            continue;
        vector<int> tmp = mp[i];
        sort(tmp.begin(), tmp.end(), comp);
        for(int x : tmp)
            ans += to_string(x);
    }
    return ans;
}
