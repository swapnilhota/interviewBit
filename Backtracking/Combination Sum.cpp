void helper(vector<int> A, int B, int idx, set<vector<int>> &ans, vector<int> v, long long sum)
{
    if(idx==A.size())
    {
        return;
    }
    if(sum>B)
    {
        return;
    }
    if(sum==B)
    {
        sort(v.begin(), v.end());
        ans.insert(v);
        return;
    }
    
    helper(A, B, idx+1, ans, v, sum);
    v.push_back(A[idx]);
    sum+=A[idx];
    helper(A, B, idx, ans, v, sum);
    helper(A, B, idx+1, ans, v, sum);
    
    
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    
    long long sum=0;
    vector<int> v;
    set<vector<int>> ans;
    
    helper(A, B, 0, ans, v, sum);
    
    vector<vector<int>> res;
    
    for(auto i:ans)
    {
        res.push_back(i);
    }
    
    return res;
    
}
