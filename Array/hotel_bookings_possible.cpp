
bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n =arrive.size();
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int i = 0;
    int j = 0;
    int ans = 0;
    int max_ans = 0;
    while(i<n && j<n) {
        if(arrive[i] < depart[j]) {
            i++;
            ans++;
            max_ans = max(max_ans, ans);
        }
        else {
            j++;
            ans--;
        }
    }
    return max_ans<=K;
}
