vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(), A.end());
    
    for(int i=0; i<A.size(); i+=2) {
        if(i+1 < A.size()) {
            swap(A[i], A[i+1]);
        }
        
    }
    
    return A;
    
}
