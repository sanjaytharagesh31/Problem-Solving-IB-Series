// O(B) solution
int Solution::solve(vector<int> &A, int B, int C) {
    if(A.size() == 0)
        return 0;
    int c_d = floor(log10(C))+1;
    // cout << c_d << endl;
    if(B > c_d) {
        return 0;
    }
    else if(B < c_d) {
        int ans = 1;
        for(int i=1; i<=B; i++) {
            if(i == 1 && A[0] == 0 && B!=1)
                ans = ans * (A.size()-1);
            else
                ans = ans * A.size();
        }
        return ans;
    } 
    else {
        int ans = 0;
        int lower[15] = {};
        int find[15] = {};
        for(int i=0; i<A.size(); i++) {
            lower[A[i]+1] = 1;
            find[A[i]] = 1;
        }
        for(int i=1; i<10; i++)
            lower[i] += lower[i-1];
        for(int i=c_d-1; i>=0; i--) {
            int d = C/pow(10, i);
            C = C % (int)pow(10, i);
            // int cnt = lower_bound(A.begin(), A.end(), d)-A.begin();
            int cnt = lower[d];
            if(i == c_d-1 && A[0] == 0 && B!=1)
                ans += (cnt-1)*(int)pow(A.size(), i);
            else
                ans += cnt*(int)pow(A.size(), i);
            if(find[d] == 0) {
                break;
            }
        }
        return ans;
    }
}

// O(B * logD) Solution (D - number of digits in A array)
// int Solution::solve(vector<int> &A, int B, int C) {
//     if(A.size() == 0)
//         return 0;
//     int c_d = floor(log10(C))+1;
//     // cout << c_d << endl;
//     if(B > c_d) {
//         return 0;
//     }
//     else if(B < c_d) {
//         int ans = 1;
//         for(int i=1; i<=B; i++) {
//             if(i == 1 && A[0] == 0 && B!=1)
//                 ans = ans * (A.size()-1);
//             else
//                 ans = ans * A.size();
//         }
//         return ans;
//     }
//     else {
//         int ans = 0;
//         for(int i=c_d-1; i>=0; i--) {
//             int d = C/pow(10, i);
//             C = C % (int)pow(10, i);
//             int cnt = lower_bound(A.begin(), A.end(), d)-A.begin();
//             if(i == c_d-1 && A[0] == 0 && B!=1)
//                 ans += (cnt-1)*(int)pow(A.size(), i);
//             else
//                 ans += cnt*(int)pow(A.size(), i);
//             if(find(A.begin(), A.end(), d) == A.end()) {
//                 break;
//             }
//         }
//         return ans;
//     }
// }
