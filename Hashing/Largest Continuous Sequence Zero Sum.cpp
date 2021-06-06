vector<int> Solution::lszero(vector<int> &A) {
    
    map<int, int> mp;
    
    int len=0;
    
    int l=-1, r=-1;
    
    int sum=0;
    
    for(int i=0; i<A.size(); i++)
    {
        sum += A[i];
        if(sum==0)
        {
            len=i+1;
            l=0;
            r=i;
            continue;
        }
        if(mp.find(sum)!=mp.end())
        {
            int tmp = i-mp[sum];
            if(tmp>len)
            {
                len=tmp;
                l=mp[sum]+1;
                r=i;
            }
        }
        else
        {
            mp[sum] = i;
        }
    }
    
    vector<int> ans;
    
    if(l==-1)
    {
        return ans;
    }
    
    for(int i=l; i<=r; i++)
    {
        ans.push_back(A[i]);
    }
    
    return ans;
    
}
