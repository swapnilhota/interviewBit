vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    vector<vector<int>> ans;
    map<string, vector<int>> mp;
    
    int n = A.size();
    
    for(int i=0; i<n; i++)
    {
        string s = A[i];
        sort(s.begin(), s.end());
        mp[s].push_back(i+1);
    }
    
    for(auto i:mp)
    {
        ans.push_back(i.second);
    }
    
    return ans;
    
}
