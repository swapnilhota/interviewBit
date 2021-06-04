int Solution::solve(vector<int> &A, int B) {
    
    int ans=0;
    int tmp=0;
    
    unordered_map<int, int> m;
    
    for(int i=0; i<A.size(); i++)
    {
        tmp^=A[i];
        if(tmp==B)
        {
            ans++;
        }
        if(m.find(tmp^B)!=m.end())
        {
            ans += m[tmp^B];
        }
        m[tmp]++;
    }
    
    return ans;
    
}
