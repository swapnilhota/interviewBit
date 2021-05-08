vector<vector<int> > Solution::solve(int A) {
    
    vector<vector<int>> ans;
    if(A==0)
    {
        return ans;
    }
    vector<int> v;
    v.push_back(1);
    ans.push_back(v);
    if(A==1)
    {
        return ans;
    }
    v.push_back(1);
    ans.push_back(v);
    if(A==2)
    {
        return ans;
    }
    for(int i=2; i<A; i++)
    {
        vector<int> v;
        v.push_back(1);
        for(int j=1; j<=i-1; j++)
        {
            int x = ans[i-1][j]+ans[i-1][j-1];
            v.push_back(x);
        }
        v.push_back(1);
        ans.push_back(v);
    }
    
    return ans;
}
