int Solution::solve(vector<int> &A, int B) {
    
    int ans=0;
    
    priority_queue<int> maxHeap;
    
    for(auto i: A)
    {
        maxHeap.push(i);
    }
    
    while(B>0)
    {
        int tmp = maxHeap.top();
        maxHeap.pop();
        ans += tmp;
        tmp--;
        maxHeap.push(tmp);
        B--;
    }
    
    return ans;
    
}
