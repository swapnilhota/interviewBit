void helper(int A, int B, set<set<int>> &ans, set<int> s, int x)
{
    if(x>A)
    {
        if(s.size()==B)
        {
            ans.insert(s);
            return;
        }
        return;
    }
    if(s.size()==B)
    {
        ans.insert(s);
        return;
    }
    if(s.size()>B)
    {
        return;
    }
    
    helper(A, B, ans, s, x+1);
    s.insert(x);
    helper(A, B, ans, s, x+1);
}

vector<vector<int> > Solution::combine(int A, int B) {
    
    set<set<int>> ans;
    set<int> s;
    
    helper(A, B, ans, s, 1);
    
    vector<vector<int>> res;
    
    for(auto i:ans)
    {
        vector<int> tmp;
        for(auto j:i)
        {
            tmp.push_back(j);
        }
        res.push_back(tmp);
    }
    
    return res;
    
}
