string Solution::simplifyPath(string A) {
    
    deque<string> dq;
    
    string temp="";
    
    for(char c:A)
    {
        if(temp=="")
        {
            temp+=c;
        }
        else
        {
            if(c=='/')
            {
                if(temp=="/." || temp=="/")
                {
                    temp="";
                }
                else if(temp=="/..")
                {
                    if(!dq.empty())
                    {
                        dq.pop_back();
                    }
                    temp="";
                }
                else
                {
                    dq.push_back(temp);
                    temp="";
                }
                temp+=c;
            }
            else
            {
                temp+=c;
            }
        }
    }
    
    if(temp!="")
    {
        if(temp=="/." || temp=="/")
        {
            temp="";
        }
        else if(temp=="/..")
        {
            if(!dq.empty())
            {
                dq.pop_back();
            }
            temp="";
        }
        else
        {
            dq.push_back(temp);
            temp="";
        }
    }
    
    string ans="";
    
    while(!dq.empty())
    {
        ans.append(dq.front());
        dq.pop_front();
    }
    
    if(ans=="")
    {
        ans += "/";
    }
    
    return ans;
    
}
