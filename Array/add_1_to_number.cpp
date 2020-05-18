vector<int> Solution::plusOne(vector<int> &A) {
    int f = 0;
    vector<int> v;
    for(int i=0; i<A.size(); i++) {
        if(A[i] != 0 || i==A.size()-1) {
            f = 1;
            v.push_back(A[i]);
        }
        else if (f == 1) {
            v.push_back(A[i]);
        }
    }
    int n = v.size();
    // cout << v[0] << " --- " <<endl;
    // for(auto x : v)
    //     cout << x << " ";
    // cout << endl;
    if(v[n-1] <= 8)
        v[n-1] += 1;
    else {
        reverse(v.begin(), v.end());
        v[0] = 0;
        int car = 1;
        for(int i=1; i<n; i++) {
            int sum = v[i] + car;
            v[i] = sum%10;
            car = sum/10;
        }
        if(car != 0) {
            v.push_back(car);
        }
        reverse(v.begin(), v.end());
    }
    return v;
}
