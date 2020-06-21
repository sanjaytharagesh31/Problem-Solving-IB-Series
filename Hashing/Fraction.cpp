//weird question

string Solution::fractionToDecimal(int n, int d) {
    if(n == 0 || d == 0)
        return "0";
    string ans = "";
    if((n<0) ^ (d<0)) {
        // cout << n << " " << d << endl;
        ans = "-";
    }
    long long int A = abs((long long int)n);
    long long int B = abs((long long int)d);
    // cout << ans << " --- " << endl;
    ans += to_string(A/B);
    // cout << ans << " --- " << endl;
    if(A%B == 0)
        return ans;
    else {
        ans += '.';
        map<long long int, long long int> mp;
        long long int rem = A%B;
        rem = rem*10;
        while(rem > 0) {
            if(mp.find(rem) != mp.end()) {
                ans.insert(mp[rem], 1, '(');
                ans += ')';
                break;
            }
            else {
                mp[rem] = ans.size();
                ans += to_string(rem/B);
                rem = (rem%B)*10;
            }
        }
    }
    return ans;
}
