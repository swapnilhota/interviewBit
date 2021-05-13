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
    return a.start < b.start;
} 

vector<Interval> Solution::merge(vector<Interval> &A) {
    
    sort(A.begin(), A.end(), compare);
    
    int n = A.size();
    
    if(n==1 || n==0) {
        return A;
    }
    
    Interval prev = A[0];
    
    vector<Interval> ans;
    
    for(int i=1; i<n; i++) {
        if(A[i].start <= prev.end) {
            prev.end = max(prev.end, A[i].end);
            
        } else {
            ans.push_back(prev);
            prev=A[i];
        }
    }
    
    ans.push_back(prev);
    
    return ans;
    
}
