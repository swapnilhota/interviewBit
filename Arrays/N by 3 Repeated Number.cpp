int Solution::repeatedNumber(const vector<int> &A) {
    
    int cnt1=0;
    int cnt2=0;
    int term1 = -1;
    int term2 = -1;
    
    for(int i=0; i<A.size(); i++) {
        if(term1==A[i]) {
            cnt1++;
        }
        else if(term2==A[i]) {
            cnt2++;
        }
        else if(cnt1==0) {
            cnt1++;
            term1 = A[i];
        }
        else if(cnt2==0) {
            cnt2++;
            term2 = A[i];
        }
        else {
            cnt1--;
            cnt2--;
        }
    }
    
    cnt1=0;
    cnt2=0;
    
    for(int i=0; i<A.size(); i++) {
        if(A[i]==term1) {
            cnt1++;
        }
        else if(A[i]==term2) {
            cnt2++;
        }
    }
    
    if(cnt1 > A.size()/3) {
        return term1;
    }
    
    if(cnt2 > A.size()/3) {
        return term2;
    }
    
    return -1;
    
}
