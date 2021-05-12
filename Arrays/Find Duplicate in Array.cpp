int Solution::repeatedNumber(const vector<int> &A) {
    
    int n = A.size();
    
    int cnt[n-1] = {0};
    
    for(int i=0; i<A.size(); i++) {
        cnt[A[i]-1]++;
        if(cnt[A[i]-1]>1) {
            return A[i];
        }
    }
    
    return -1;
}
