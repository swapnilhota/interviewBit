int Solution::solve(vector<int> &A) {
    
    int n=A.size();
    
    unordered_map<int, int> m;
    
    int sum=0;
    
    int ans=0;
    
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]==1)
        {
            sum++;
        }
        else
        {
            sum--;
        }
        if(sum==1)
        {
            ans=i+1;
        }
        else if(m.find(sum)==m.end())
        {
            m[sum]=i;
        }
        if(m.find(sum-1)!=m.end())
        {
            ans = max(ans, i-m[sum-1]);
        }
    }
    
    return ans;
}
