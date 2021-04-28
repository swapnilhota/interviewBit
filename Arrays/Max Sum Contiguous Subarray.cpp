int Solution::maxSubArray(const vector<int> &A) {
    
    int ans[A.size()];
    
    ans[0] = A[0];
    
    for(int i=1; i<A.size(); i++) {
        if(A[i]+ans[i-1]>A[i]) {
            ans[i] = A[i]+ans[i-1];
        }
        else {
            ans[i] = A[i];
        }
    }
    
    int res = INT_MIN;
    
    for(int i=0; i<A.size(); i++) {
        res = max(res, ans[i]);
    }
    
    return res;
    
}
