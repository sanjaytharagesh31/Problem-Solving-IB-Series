O(Length of Number) Time and space complexity
int Solution::colorful(int A) {
    int d = floor(log10(A)+1);
    vector<int> ans;
    while(A > 0) {
        ans.push_back(A%10);
        A = A/10;
    }
    reverse(ans.begin(), ans.end());
    map<long long int, long long int> mp;
    for(int i=0; i<d; i++) {
        int mul = 1;
        for(int j=i; j<d; j++) {
            mul *= ans[j];
            mp[mul]++;
            if(mp[mul] > 1) 
                return 0;
        }
    }
    return 1;
}
