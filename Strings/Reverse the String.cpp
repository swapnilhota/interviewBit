string Solution::solve(string A) {
    
    vector<string> v;
    string temp="";
    for(char i : A)
    {
        if(i==' ')
        {
            if(temp!="")
            {
                v.push_back(temp);
                temp="";
            }
        }
        else
        {
            temp += i;
        }
    }
    
    if(temp!="")
    {
        v.push_back(temp);
    }
    
    string ans = "";
    
    for(int i=v.size()-1; i>0; i--)
    {
        ans += v[i];
        ans += " ";
    }
    
    ans += v[0];
    
    return ans;
    
}
