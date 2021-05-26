int Solution::solve(string A) {
    
    stack<char> s;
    
    for(char c:A)
    {
        if(c=='(')
        {
            s.push('(');
        }
        else
        {
            if(s.empty())
            {
                return 0;
            }
            else if(s.top()=='(')
            {
                s.pop();
            }
            else
            {
                return 0;
            }
        }
    }
    
    if(s.empty())
    {
        return 1;
    }
    
    return 0;
    
}
