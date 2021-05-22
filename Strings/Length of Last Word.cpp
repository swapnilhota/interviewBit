int Solution::lengthOfLastWord(const string A) {
    
    vector<string> v;
    
    string temp="";
    
    for(char i: A)
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
    
    if(v.size()>0)
    {
        return v[v.size()-1].length();
    }
    
    return 0;
    
}
