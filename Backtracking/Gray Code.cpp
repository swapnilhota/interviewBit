int convert(string s)
{
    int ans=0;
    int p=0;
    for(int i=s.length()-1; i>=0; i--)
    {
        ans += (s[i]-'0')*(int)pow(2, p);
        p++;
    }
    return ans;
}

vector<int> Solution::grayCode(int A) {
    
    vector<string> v;
    
    string init="";
    
    for(int i=0; i<A; i++)
    {
        init += to_string(0);
    }
    
    v.push_back(init);
    
    unordered_map<string, int> m;
    m[init]=1;
    
    int i=init.length()-1;
    
    while(i>=0)
    {
        string tmp = init;
        if(tmp[i]=='0')
        {
            tmp[i]='1';
        }
        else
        {
            tmp[i]='0';
        }
        if(m[tmp]!=0)
        {
            i--;
            continue;
        }
        else
        {
            m[tmp]=1;
            v.push_back(tmp);
            init=tmp;
            i=init.length()-1;
        }
    }
    
    vector<int> ans;
    
    for(string s:v)
    {
        ans.push_back(convert(s));
    }
    
    return ans;
    
}
