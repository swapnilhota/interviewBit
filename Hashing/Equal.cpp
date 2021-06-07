bool check(vector<int> ans, vector<int> tmp)
{
    if(ans.size()==0)
    {
        return true;
    }
    vector<vector<int>> v;
    v.push_back(ans);
    v.push_back(tmp);
    sort(v.begin(), v.end());
    if(v[0]==ans)
    {
        return false;
    }
    
    return true;
}

vector<int> Solution::equal(vector<int> &A) {
    
    unordered_map<int, pair<int, int>> mp;
    vector<int> ans;
    
    for(int i=0; i<A.size()-1; i++)
    {
        for(int j=i+1; j<A.size(); j++)
        {
            int sum = A[i]+A[j];
            if(mp.find(sum)!=mp.end())
            {
                auto p = mp[sum];
                if(i!=p.first && i!=p.second)
                {
                    if(j!=p.first && j!=p.second)
                    {
                        vector<int> tmp;
                        tmp.push_back(p.first);
                        tmp.push_back(p.second);
                        tmp.push_back(i);
                        tmp.push_back(j);
                        if(check(ans, tmp))
                        {
                            ans=tmp;
                        }
                    }
                }
            }
            else
            {
                mp[sum] = {i, j};
            }
        }
    }
    
    return ans;
}
