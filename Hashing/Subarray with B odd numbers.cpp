int Solution::solve(vector<int> &A, int B) {
    
    vector<int> v;
    
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]%2!=0)
        {
            v.push_back(i);
        }
    }
    
    if(v.size()<B)
    {
        return 0;
    }
    
    if(B==0)
    {
        if(v.size()==0)
        {
            return ((A.size())*(A.size()+1))/2;
        }
        
        int cnt=0;
        int i=0;
        int j=0;
        
        set<pair<int, int>> s;
        
        while(j<A.size())
        {
            if(A[j]%2!=0)
            {
                j++;
                i=j;
            }
            else
            {
                s.insert(make_pair(i, j));
                j++;
            }
        }
        
        return s.size();
    }
    
    int ans=0;
    int l=0;
    int r=B-1;
    
    while(r<v.size())
    {
        int left;
        int right;
        if(l==0)
        {
            left = v[l]+1;
        }
        else
        {
            left = v[l]-v[l-1];
        }
        
        if(r==v.size()-1)
        {
            right = A.size()-v[r];
        }
        else
        {
            right = v[r+1]-v[r];
        }
        
        ans += left*right;
        l++;
        r++;
    }
    
    return ans;
    
}
