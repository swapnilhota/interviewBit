int Solution::solve(string A) {
    
    stack<char> s;
    
    for(char i:A)
    {
        if(s.empty())
        {
            s.push(i);
            continue;
        }
        if(i=='(')
        {
            s.push(i);
        }
        else
        {
            if(s.top()=='(')
            {
                s.pop();
            }
            else
            {
                s.push(')');
            }
        }
    }
    
    return s.size();
    
}
