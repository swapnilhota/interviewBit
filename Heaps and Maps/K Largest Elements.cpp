vector<int> Solution::solve(vector<int> &A, int B) {
    
    priority_queue<int, vector<int>, greater<int> > minHeap;
    
    for(int i=0; i<A.size(); i++)
    {
        minHeap.push(A[i]);
        if(minHeap.size()>B)
        {
            minHeap.pop();
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
