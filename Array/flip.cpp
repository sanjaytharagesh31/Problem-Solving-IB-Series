vector<int> Solution::flip(string str) {
    int l = str.length();
    int seg = 0;
    vector<vector<int>> v(l, vector<int>(2, 0));
    vector<int> ans;
    if(str[l-1] == '0')
        v[l-1][0] = 1;
    for(int i=l-2; i>=0; i--) {
        if(str[i] == '0') {
            v[i][0] = v[i+1][0]+1;
            v[i][1] = v[i+1][1];
        }
        else if(v[i+1][0] > v[i+1][1]+1) {
            v[i][0] = v[i+1][0];
            v[i][1] = v[i+1][1]+1;
        }
        if(v[i][0]-v[i][1]!=0 && v[i][0]-v[i][1] >= seg) {
            ans = vector<int>(2);
            ans[0] = i+1;
            ans[1] = i+(v[i][0]+v[i][1]);
            seg = v[i][0]-v[i][1];
        }
    }
    return ans;
}
