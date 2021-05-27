#define M 1000000007

int Solution::maxSpecialProduct(vector<int> &A) {
    
    long long n = A.size();
    stack<long long> s;
    vector<long long> right;
    vector<long long> left;
    
    for(long long i=0; i<n; i++)
    {
        while(!s.empty() && A[s.top()]<=A[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            left.push_back(0);
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
    
    for(long long i=n-1; i>=0; i--)
    {
        while(!s.empty() && A[s.top()]<=A[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            right.push_back(0);
        }
        else
        {
            right.push_back(s.top());
        }
        s.push(i);
    }
    
    reverse(right.begin(), right.end());
    
    long long ans=0;
    
    for(long long i=0; i<n; i++)
    {
        ans = max(ans, left[i]*right[i]);
    }
    
    return ans%M;
}
