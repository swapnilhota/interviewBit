int Solution::solve(vector<int> &A, int B) {
    
    unordered_map<int, int> m;
    for(int i=0; i<A.size(); i++)
    {
        m[A[i]]++;
    }

    
    for(int i=0; i<A.size(); i++)
    {
        if(m[A[i]-B] || m[A[i]+B])
        {
            if(B==0)
            {
                if(m[A[i]]>1)
                {
                    return 1;
                }
            }
            else
            {
                return 1;
            }
        }
    }
    
    return 0;
    
}
