/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compare(Interval a, Interval b) {
    return a.start<b.start;
} 

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int n = intervals.size();
    if(n==0) {
        vector<Interval> v;
        v.push_back(newInterval);
        return v;
    }
    
    if(newInterval.end < intervals[0].start) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), compare);
        return intervals;
    }
    
    if(newInterval.start > intervals[n-1].end) {
        intervals.push_back(newInterval);
        return intervals;
    }
    
    if(newInterval.start < intervals[0].start && newInterval.end > intervals[n-1].end) {
        intervals.clear();
        intervals.push_back(newInterval);
        return intervals;
    }
    
    int left=-1;
    int right=n;
    
    for(int i=0; i<n; i++) {
        if(newInterval.start >= intervals[i].start) {
            if(newInterval.start <= intervals[i].end) {
                left=i;
                break;
            }
            else {
                left=i+1;
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        if(newInterval.end >= intervals[i].start) {
            right=i;
        }
    }
    
    //cout << "left = " << left << endl;
    //cout << "right = " << right << endl;
    
    if(left==-1 && right==n) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), compare);
        return intervals;
    }
    
    if(left==-1) {
        newInterval.end = max(newInterval.end, intervals[right].end);
    }
    else if(right==n) {
        newInterval.start = min(newInterval.start, intervals[left].start);
    }
    else {
        newInterval.start = min(newInterval.start, intervals[left].start);
        newInterval.end = max(newInterval.end, intervals[right].end);
    }
    
    int l = max(left, 0);
    int r = min(right, n-1);
    
    auto it = intervals.begin();
    
    intervals.erase(it+l, it+r+1);
    
    intervals.push_back(newInterval);
    
    sort(intervals.begin(), intervals.end(), compare);
    
    return intervals;
}
