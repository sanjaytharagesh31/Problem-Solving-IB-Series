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

    //Single Pass solution
    vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    bool flag = false;
    vector<Interval> ans;
    for(int i=0; i<intervals.size(); i++) {
        if(intervals[i].end < newInterval.start) {
            ans.push_back(intervals[i]);
        }
        else if(intervals[i].start > newInterval.end) {
            if(flag == true)
                ans.push_back(intervals[i]);
            else {
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                flag = true;
            }
        }
        else {
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
    }
    if(flag == false)
        ans.push_back(newInterval);
    return ans;
}
