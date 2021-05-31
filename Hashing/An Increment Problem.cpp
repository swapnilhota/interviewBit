vector<int> Solution::solve(vector<int> &A) {
    
    map<int, vector<int>> m;
    
    for(int i=0; i<A.size(); i++)
    {
        if(m[A[i]].size()==0)
        {
            m[A[i]].push_back(i);
        }
        else
        {
            int idx = m[A[i]][0];
            m[A[i]][0]=i;
            A[idx]++;
            if(m[A[idx]].size()==0)
            {
                m[A[idx]].push_back(idx);
            }
            else
            {
                m[A[idx]][0] = min(m[A[idx]][0], idx);
            }
        }
    }
    
    return A;
    
}
