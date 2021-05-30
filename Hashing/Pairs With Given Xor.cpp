int Solution::solve(vector<int> &A, int B) {
    
    set<pair<int, int>> s;
    map<int, int> m;
    
    for(int i:A)
    {
        m[i]++;
    }
    
    for(int i:A)
    {
        if(m[i^B])
        {
            s.insert(make_pair(min(i, i^B), max(i, i^B)));
        }
    }
    
    return s.size();
    
}
