//O(nlogn)

vector<int> Solution::subUnsort(vector<int> &A) {
    vector<int> tmp(A);
    sort(tmp.begin(), tmp.end());
    int s=-1, e=-1;
    for(int i=0; i<A.size(); i++) {
        if(A[i] != tmp[i]) {
            s = i;
            break;
        }
    }
    for(int i=A.size()-1; i>=0; i--) {
        if(A[i] != tmp[i]) {
            e = i;
            break;
        }
    }
    if(s==-1 || e==-1 || s==e)
        return vector<int>{-1};
    else
        return vector<int>{s, e};
}

//O(N) solution
vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    int i=0;
    while(i<n-1) {
        if(A[i] <= A[i+1])
            i++;
        else 
            break;
    }
    if(i == n-1)
        return vector<int>{-1};
    int j=n-1;
    while(j>=0) {
        if(A[j] >= A[j-1])
            j--;
        else
            break;
    }
    if(i > j)
        swap(i, j);
    int max_sub = INT_MIN;
    int min_sub = INT_MAX;
    int start = i;
    int end = j;
    // cout << "i: " << i << endl;
    // cout << "j: " << j << endl;
    for(int p=i; p<=j; p++) {
        max_sub = max(max_sub, A[p]);
        min_sub = min(min_sub, A[p]);
    }
    for(int p=0; p<i; p++) {
        if(A[p] > min_sub){
            start = p;
            break;
        }
    }
    for(int p=n-1; p>j; p--) {
        if(A[p] < max_sub) {
            end = p;
            break;
        }
    }
    return vector<int>{start, end};
}
