//KMP Algorithm 
#include <bits/stdc++.h>
using namespace std;

int main() {
    string txt = "abcdabcd"; 
    string pat = "cda"; 
    int m = txt.length();
    int n = pat.length();
    vector<int> arr(n);
    arr[0] = 0;
    int i = 0;
    int j = 1;
    while(j<n) {
        if(pat[i] == pat[j])
            arr[j++] = i++;
        else {
            if(i > 0)
                i = arr[i-1];
            else
                arr[j++] = 0;
        }
    }
    i=0;
    j=0;
    while(i<m) {
        if(txt[i] == pat[j]) {
            i++;
            j++;
            if(j == n) {
                cout << i - n << endl;
                j = arr[j-1];
            }
        }
        else {
            if(j > 0)
                j = arr[j-1];
            else
                i++;
        }
    }
}

//TODO: Fix bugs in Aux array
int Solution::strStr(const string A, const string B) {
    int m = A.length();
    int n = B.length();
    if(n == 0 || (m==0 && n==0))
        return -1;
    vector<int> arr(n, 0);
    int ind = 0;
    for(int i=1; i<n; i++) {
        if(B[ind] == B[i])
            arr[i] = ++ind;
        else
            ind = 0;
    }
    // cout << "Array" << endl;
    // for(int x : arr)
    //     cout << x << " ";
    // cout << endl;
    int j = 0;
    int i=0;
    for(;i<m;) {
        if(A[i] == B[j]) {
            j++;
            i++;
            if(j == n)
                return i-n;
        }
        else {
            if(j > 0)
                j = arr[j-1];
            else
                i++;
        }
    }
    return -1;
}
