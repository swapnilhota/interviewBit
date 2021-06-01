void helper(vector<int> A, set<vector<int>> &ans, vector<int> v, int idx)
{
    if(idx==A.size())
    {
        return;
    }
    
    ans.insert(v);
    helper(A, ans, v, idx+1);
    
    v.push_back(A[idx]);
    ans.insert(v);
    helper(A, ans, v, idx+1);
}


vector<vector<int> > Solution::subsets(vector<int> &A) {
    
    sort(A.begin(), A.end());
    
    set<vector<int>> ans;
    vector<int> v;
    ans.insert(v);
    
    for(int i=0; i<A.size(); i++)
    {
        helper(A, ans, v, i);
    }
    
    vector<vector<int>> res;
    
    for(auto i:ans)
    {
        res.push_back(i);
    }
    
    return res;
    
}
