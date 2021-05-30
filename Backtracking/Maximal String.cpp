string helper(string A, int B, int idx)
{
    if(B==0)
    {
        return A;
    }
    if(idx==A.length()-1)
    {
        return A;
    }
    
    vector<string> v;
    
    for(int i=idx+1; i<A.length(); i++)
    {
        if(A[i]>A[idx])
        {
            string tmp = A;
            swap(tmp[i], tmp[idx]);
            string res = helper(tmp, B-1, idx+1);
            v.push_back(res);
        }
    }
    
    if(v.size()==0)
    {
        return helper(A, B, idx+1);
    }
    
    sort(v.begin(), v.end());
    
    return v[v.size()-1];
}

string Solution::solve(string A, int B) {
    
    int n = A.length();
    
    return helper(A, B, 0);
}
