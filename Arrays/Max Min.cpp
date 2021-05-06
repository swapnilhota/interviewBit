int Solution::solve(vector<int> &A) {
    
    int maxTerm = INT_MIN;
    int minTerm = INT_MAX;
    
    for(int i=0; i<A.size(); i++)
    {
        maxTerm = max(maxTerm, A[i]);
        minTerm = min(minTerm, A[i]);
    }
    
    return maxTerm+minTerm;
    
}
