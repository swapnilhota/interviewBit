bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.second<b.second)
    {
        return true;
    }
    else if(a.second==b.second)
    {
        if(a.first<b.first)
        {
            return true;
        }
        
        return false;
    }
    
    return false;
}

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    
    vector<pair<int, int>> v;
    
    map<int, vector<int>> m;
    
    for(int i=0; i<A.size(); i++)
    {
        m[A[i]].push_back(i+1);
    }
    
    for(int i=0; i<A.size(); i++)
    {
        if(m[B-A[i]].size()>0)
        {
            vector<int> tmp = m[B-A[i]];
            int idx1 = i+1;
            int idx2=-1;
            for(auto idx: tmp)
            {
                if(idx>idx1)
                {
                    idx2=idx;
                    break;
                }
            }
            if(idx2!=-1)
            {
                v.push_back(make_pair(idx1, idx2));
            }
        }
    }
    
    if(v.size()==0)
    {
        vector<int> temp;
        return temp;
    }
    
    sort(v.begin(), v.end(), compare);
    
    auto tmp = v[0];
    
    vector<int> ans;
    ans.push_back(tmp.first);
    ans.push_back(tmp.second);
    
    return ans;
    
}
