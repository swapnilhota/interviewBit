int Solution::maximumGap(const vector<int> &A) {
    if(A.size()<2){
        return 0;
    }
    
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    for(int i=0; i<A.size(); i++) {
        minHeap.push(A[i]);
    }
    
    int ans = 0;
    int prev = minHeap.top();
    minHeap.pop();
    
    while(!minHeap.empty()) {
        ans = max(ans, minHeap.top()-prev);
        prev = minHeap.top();
        minHeap.pop();
    }
    
    return ans;
    
}
