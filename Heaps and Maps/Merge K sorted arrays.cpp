vector<int> Solution::solve(vector<vector<int> > &A) {
    
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[0].size(); j++)
        {
            minHeap.push(A[i][j]);
        }
    }
    
    vector<int> ans;
    
    while(!minHeap.empty())
    {
        ans.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return ans;
    
}
