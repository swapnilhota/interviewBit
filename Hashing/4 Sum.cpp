bool compare(vector<int> a, vector<int> b)
{
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]<b[i])
        {
            return true;
        }
        else if(a[i]>b[i])
        {
            return false;
        }
    }
    
    return false;
}

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    
    sort(A.begin(), A.end());
    
    map<int, vector<pair<int, int>>> m;
    
    int n = A.size();
    
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int sum = A[i]+A[j];
            pair<int, int> p = make_pair(i, j);
            m[sum].push_back(p);
        }
    }
    
    set<vector<int>> ans;
    
    for(auto i:m)
    {
        int sum = i.first;
        vector<pair<int, int>> v1 = i.second;
        
        if(m[B-sum].size()==0)
        {
            continue;
        }
        
        vector<pair<int, int>> v2 = m[B-sum];
        for(auto a: v1)
        {
            
            for(auto b: v2)
            {
                set<int> idx;
                idx.insert(a.first);
                idx.insert(a.second);
                idx.insert(b.first);
                idx.insert(b.second);
                if(idx.size()==4)
                {
                    vector<int> tmp;
                    tmp.push_back(A[a.first]);
                    tmp.push_back(A[a.second]);
                    tmp.push_back(A[b.first]);
                    tmp.push_back(A[b.second]);
                    sort(tmp.begin(), tmp.end());
                    ans.insert(tmp);
                }
            }
        }
    }
    
    vector<vector<int>> res;
    for(auto i: ans)
    {
        res.push_back(i);
    }
    sort(res.begin(), res.end(), compare);
    
    return res;
    
}
