int Solution::firstMissingPositive(vector<int> &A) {
    int max_pos = -1;
    for(int i=0; i<A.size(); i++) {
        max_pos = max(max_pos, A[i]);
    }
    
    if(max_pos < 1) {
        return 1;
    }
    
    bool* posTerms = new bool[max_pos+2]();
    
    for(int i=0; i<A.size(); i++) {
        posTerms[A[i]]=true;
    }
    
    for(int i=1; i<max_pos+2; i++) {
        if(posTerms[i]==false) {
            return i;
        }
    }
    
    return max_pos+1;
}
