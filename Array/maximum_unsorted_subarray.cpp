//)(nlogn)

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
