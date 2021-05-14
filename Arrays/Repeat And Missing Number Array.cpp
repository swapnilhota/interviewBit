vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int freq[n+1] = {0};
    
    for(int i=0; i<n; i++) {
        freq[A[i]]++;
    }
    
    int repTerm;
    int missTerm;
    
    for(int i=1; i<=n; i++) {
        if(freq[i]==0) {
            missTerm=i;
        }
        if(freq[i]>1) {
            repTerm = i;
        }
    }
    
    vector<int> v;
    v.push_back(repTerm);
    v.push_back(missTerm);
    
    return v;
}
