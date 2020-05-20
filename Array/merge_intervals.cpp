//Insert the interval first, then merge the overlapping intervals
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    bool flag = false;
    vector<Interval> ans;
    for(int i=0; i<intervals.size(); i++) {
        if(intervals[i].start >= newInterval.start) {
            intervals.insert(intervals.begin()+i, newInterval);
            flag = true;
            break;
        }
    }
    if(!flag)
        intervals.push_back(newInterval);
    Interval prev = intervals[0];
    for(int i=1; i<intervals.size(); i++) {
        if(intervals[i].start <= prev.end) {
            prev.end = max(prev.end, intervals[i].end);
        else {
            ans.push_back(prev);
            prev = intervals[i];
        }
    }
    ans.push_back(prev);
    return ans;
}
