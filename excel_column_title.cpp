string Solution::convertToTitle(int A) {
    string str = "";
    unordered_map<int, char> mp;
    char ch = 'A';
    for(int i=1; i<=25; i++, ch++) 
        mp[i] = ch;
    mp[0] = 'Z';
    while(A > 0) {
        int rem = A % 26;
        A /= 26;
        if(rem == 0)
            A--;
        str += mp[rem];
    }
    reverse(str.begin(), str.end());
    return str;
}
