int Solution::solve(string A) {
    
    map<char, int> m;
    
    for(char c:A)
    {
        m[c]++;
    }
    
    if(A.length()%2==0)
    {
        for(auto i:m)
        {
            if(i.second%2!=0)
            {
                return 0;
            }
        }
    }
    else
    {
        int cnt=0;
        for(auto i:m)
        {
            if(i.second%2!=0)
            {
                cnt++;
            }
        }
        if(cnt>1)
        {
            return 0;
        }
    }
    
    return 1;
    
}
