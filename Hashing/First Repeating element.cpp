int Solution::solve(vector<int> &A) {
    
    map<int, int> m;
    for(int i:A)
    {
        m[i]++;
    }
    
    for(int i=0; i<A.size(); i++)
    {
        if(m[A[i]]>1)
        {
            return A[i];
        }
    }
    
    return -1;
    
}
