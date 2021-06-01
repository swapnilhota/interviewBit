void helper(vector<int> A, int idx, set<vector<int>> &ans, vector<int> v)
{
    if(idx==A.size())
    {
        sort(v.begin(), v.end());
        ans.insert(v);
        return;
    }
    
    helper(A, idx+1, ans, v);
    v.push_back(A[idx]);
    helper(A, idx+1, ans, v);
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    
    set<vector<int>> ans;
    vector<int> v;
    ans.insert(v);
    
    helper(A, 0, ans, v);
    
    vector<vector<int>> res;
    
    for(auto i:ans)
    {
        res.push_back(i);
    }
    
    return res;
    
}
