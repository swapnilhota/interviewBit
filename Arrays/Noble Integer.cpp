int Solution::solve(vector<int> &A) {
    
    sort(A.begin(), A.end());
    
    int n = A.size();
    
    for(int i=0; i<A.size()-1; i++) {
        if(A[i]==A[i+1]) {
            continue;
        }
        if(A[i]==n-i-1) {
            return 1;
        }
    }
    
    if(A[A.size()-1]==0) {
        return 1;
    }
    
    return -1;
}
