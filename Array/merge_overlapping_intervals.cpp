/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval i1, Interval i2) {
    if(i1.start <= i2.start)
        return true;
    else
        return false;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> ans;
    sort(A.begin(), A.end(), comp);
    Interval prev = A[0];
    for(int i=1; i<A.size(); i++) {
        if(A[i].start <= prev.end) {
            prev.end = max(prev.end, A[i].end);
        }
        else {
            ans.push_back(prev);
            prev = A[i];
        }
    }
    ans.push_back(prev);
    return ans;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
