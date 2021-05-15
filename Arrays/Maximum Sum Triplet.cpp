int Solution::solve(vector<int> &A) {
    int n = A.size();
    int maxTerm = A[n-1];
    int right[n];
    
    for(int i=n-1; i>=0; i--) {
        right[i] = maxTerm;
        maxTerm = max(A[i], maxTerm);
    }
    
    set<int> s;
    s.insert(A[0]);
    
    int ans=0;
    
    for(int i=1; i<n-1; i++) {
        if(A[i]>=right[i]) {
            continue;
        }
        s.insert(A[i]);
        auto it = s.find(A[i]);
        
        if(it==s.begin()) {
            continue;
        }
        
        it--;
        
        ans = max(ans, *it + A[i] + right[i]);
    }
    
    return ans;
    
}
