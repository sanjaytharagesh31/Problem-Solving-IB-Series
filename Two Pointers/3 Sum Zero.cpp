vector<vector<int> > Solution::threeSum(vector<int> &A) {
    sort(A.begin(), A.end());
    long long int n = A.size();
    vector<vector<int>> ans;
    set<vector<int>> s;
    for(long long int i=0; i<n-2; i++) {
        long long int x = i+1;
        long long int y = n-1;
        long long int rem = -1*(long long int)A[i];
        while(x < y) {
            if((long long int)A[x]+(long long int)A[y] == rem) {
                // ans.push_back({A[i], A[x], A[y]});
                // cout << A[i] << " " << A[x] << " " << A[y] << endl;
                s.insert({A[i], A[x], A[y]});
                x++;
                y--;
            }
            else if(A[x]+A[y] < rem)
                x++;
            else
                y--;
        }
    }
    for(auto x : s) {
        ans.push_back(x);
    }
    return ans;
}
