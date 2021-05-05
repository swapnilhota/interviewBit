vector<int> Solution::solve(vector<int> &A) {
    
    int maxTerm = INT_MIN;
    
    vector<int> v;
    
    for(int i=A.size()-1; i>=0; i--)
    {
        maxTerm = max(maxTerm, A[i]);
        if(maxTerm==A[i])
        {
            v.push_back(A[i]);
        }
    }
    
    return v;
    
}
