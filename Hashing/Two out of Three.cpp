vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    map<int, set<int>> m;
    
    for(int i:A)
    {
        m[i].insert(1);
    }
    
    for(int i:B)
    {
        m[i].insert(2);
    }
    
    for(int i:C)
    {
        m[i].insert(3);
    }
    
    vector<int> ans;
    
    for(auto i:m)
    {
        if(i.second.size()>1)
        {
            ans.push_back(i.first);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    return ans;
    
}
