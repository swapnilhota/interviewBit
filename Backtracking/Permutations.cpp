set<vector<int>> s;

void helper(vector<int> A, int idx)
{
    if(idx==A.size()-1)
    {
        return;
    }
    
    s.insert(A);
    
    helper(A, idx+1);
    
    for(int i=idx+1; i<A.size(); i++)
    {
        swap(A[idx], A[i]);
        s.insert(A);
        helper(A, idx+1);
        swap(A[idx], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    
    s.clear();
    
    if(A.size()==1)
    {
        s.insert(A);
    }
    
    helper(A, 0);
    
    vector<vector<int>> ans;
    
    for(auto i:s)
    {
        ans.push_back(i);
    }
    
    return ans;
    
}
