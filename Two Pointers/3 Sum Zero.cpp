vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    vector<vector<int>> ans;
    
    if(A.size()<3)
    {
        return ans;
    }
    
    set<vector<int>> s;
    
    sort(A.begin(), A.end());
    
    for(int i=0; i<A.size()-2; i++)
    {
        
        if(A[i]>0)
        {
            break;
        }
        
        int l=i+1;
        int r=A.size()-1;
        
        while(l<r)
        {
            long long sum = (long long)A[i]+(long long)A[l]+(long long)A[r];
            if(sum==0)
            {
                vector<int> v = {A[i], A[l], A[r]};
                s.insert(v);
                l++;
                r--;
            }
            if(sum>0)
            {
                r--;
            }
            if(sum<0)
            {
                l++;
            }
        }
    }
    
    for(auto i:s)
    {
        ans.push_back(i);
    }
    
    return ans;
    
}
