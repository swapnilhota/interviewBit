int Solution::largestRectangleArea(vector<int> &A) {
    
    stack<int> s;
    vector<int> left;
    vector<int> right;
    
    //finding next smaller element towards left
    for(int i=0; i<A.size(); i++)
    {
        while(!s.empty() && A[s.top()]>=A[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            left.push_back(-1);
        }
        else
        {
            left.push_back(s.top());
        }
        s.push(i);
    }
    
    while(!s.empty())
    {
        s.pop();
    }
    
    //finding next smaller element towards right
    for(int i=A.size()-1; i>=0; i--)
    {
        while(!s.empty() && A[s.top()]>=A[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            right.push_back(A.size());
        }
        else
        {
            right.push_back(s.top());
        }
        s.push(i);
    }
    
    reverse(right.begin(), right.end());
    
    int ans=0;
    
    for(int i=0; i<A.size(); i++)
    {
        ans = max(ans, A[i]*(right[i]-left[i]-1));
    }
    
    return ans;
    
}
