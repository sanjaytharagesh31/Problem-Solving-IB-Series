long long int mod = 1e9+7;

int power(long long int a, long long int b) {
    if(b == 0)
        return 1;
    else if(a == 0)
        return 0;
    else if(b == 1)
        return a;
    else if(b%2 == 0) {
        long long int ret = power(a, b/2); 
        return (ret%mod * ret%mod)%mod;
    }
    else {
        return (a%mod * power(a, b-1)%mod)%mod;
    }
}

int Solution::solve(int A, vector<int> &B) {
    sort(B.begin(), B.end());
    long long int tb = A - B.size(); //total blank
    long long int fact[1010];
    fact[0] = 1;
    for(long long int i=1; i<=1001; i++) 
        fact[i] = ((fact[i-1]%mod) * (i%mod))%mod;
    vector<long long int> block;
    for(long long int i=0, prev=0; i<B.size(); i++) {
        long long int val = B[i]-prev-1;
        prev = B[i];
        if(val != 0)
            block.push_back(val);
        if(i == B.size()-1 && A-B[i]!=0)
            block.push_back(A-B[i]);
    }
    // for(auto x : block)
    //     cout << x << " ";
    // cout << endl;
    vector<long long int> compress_block;
    for(long long int i=0, prev=0; i<B.size(); i++) {
        long long int val = B[i]-prev-1;
        prev = B[i];
        if(i==0 && i==B.size()-1) {
            if(val > 0)
                compress_block.push_back(1);
            if(A-B[i] > 0)
                compress_block.push_back(1);
        }
        else if(i == 0) {
            if(val > 0)
                compress_block.push_back(1);
        }
        else if(i == B.size()-1) {
            if(val > 0)
                compress_block.push_back(val);
            if(A-B[i] > 0)
                compress_block.push_back(1);
        }
        else {
            if(val > 0)
                compress_block.push_back(val);   
        }
    }
    // for(auto x : compress_block)
    //     cout << x << " ";
    // cout << endl;
    long long int answer;
    answer = fact[tb]%mod;
    // cout << "answer1 " << answer << endl;
    for(long long int i=0; i<compress_block.size(); i++) {
        if(compress_block[i] == 0)
            continue;
        answer = (answer%mod * power(2, compress_block[i]-1)%mod)%mod;
    }
    // cout << "answer2 " << answer << endl;
    long long int den = 1;
    for(long long int i=0; i<block.size(); i++) {
        den = (den%mod * fact[block[i]]%mod)%mod;
    }
    // cout << "den " << den << endl;
    answer = (answer%mod * power(den, mod-2)%mod)%mod;
    // answer = (answer / den)%mod;
    // cout << "MMI " << power(den, mod-2)%mod << endl;
    // cout << "Final " << answer << endl;
    return answer;
}
