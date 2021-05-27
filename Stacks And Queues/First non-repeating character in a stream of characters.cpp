string Solution::solve(string A) {
    
    queue<char> q;
    map<char, int> m;
    string B="";
    
    for(char c:A)
    {
        m[c]++;
        
        if(q.empty())
        {
            if(m[c]>1)
            {
                B += "#";
            }
            else
            {
                B += c;
                q.push(c);
            }
        }
        else
        {
            if(q.front()==c)
            {
                q.pop();
                if(q.empty())
                {
                    B += "#";
                }
                else
                {
                    while(m[q.front()]!=1 && !q.empty())
                    {
                        q.pop();
                    }
                    if(q.empty())
                    {
                        B += "#";
                    }
                    else
                    {
                        B += q.front();
                    }
                }
            }
            else
            {
                if(m[c]==1)
                {
                    q.push(c);
                }
                while(m[q.front()]!=1 && !q.empty())
                {
                    q.pop();
                }
                B += q.front();
            }
        }
    }
    
    return B;
    
}
