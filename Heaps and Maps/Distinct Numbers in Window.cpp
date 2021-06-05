vector<int> Solution::dNums(vector<int> &A, int B) {
    
    if(B>A.size())
    {
        vector<int> v;
        return v;
    }
    
    map<int, int> m;
    vector<int> ans;
    
    for(int i=0; i<B; i++)
    {
        m[A[i]]++;
    }
    
    ans.push_back(m.size());
    
    for(int i=B; i<A.size(); i++)
    {
        m[A[i]]++;
        m[A[i-B]]--;
        if(m[A[i-B]]==0)
        {
            m.erase(A[i-B]);
        }
        ans.push_back(m.size());
    }
    
    return ans;
    
}
