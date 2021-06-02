bool compare(vector<string> a, vector<string> b)
{
    int i=0;
    int j=0;
    
    while(i<a.size() && j<b.size())
    {
        if(a[i].length()<b[j].length())
        {
            return true;
        }
        else if(a[i].length()>b[j].length())
        {
            return false;
        }
        i++;
        j++;
    }
    
    return true;
}

bool check(string s)
{
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    if(tmp==s)
    {
        return true;
    }
    return false;
}

void helper(string A, set<vector<string>> &ans, vector<string> v, string curr, int idx)
{
    if(idx>=A.length())
    {
        if(curr!="")
        {
            if(check(curr))
            {
                v.push_back(curr);
                ans.insert(v);
                return;
            }
            
            return;
            
        }
        ans.insert(v);
        return;
    }
    
    
    curr += A.substr(idx, 1);
    if(check(curr))
    {
        helper(A, ans, v, curr, idx+1);
        v.push_back(curr);
        curr = "";
        helper(A, ans, v, curr, idx+1);
    }
    else
    {
        helper(A, ans, v, curr, idx+1);   
    }
    
}

vector<vector<string> > Solution::partition(string A) {
    
    set<vector<string>> ans;
    vector<string> v;
    string curr="";
    
    helper(A, ans, v, curr, 0);
    
    vector<vector<string>> res;
    
    for(auto i:ans)
    {
        res.push_back(i);
    }
    
    sort(res.begin(), res.end(), compare);
    
    return res;
    
}
