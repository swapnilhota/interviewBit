int Solution::braces(string A) {

    stack<char> stk;
    
    for(char c:A)
    {
        if(c=='+' || c=='-' || c=='*' || c=='/')
        {
            stk.push(c);
        }
        else if(c==')')
        {
            if(stk.top()=='(')
            {
                return 1;
            }
            else
            {
                while(stk.top()!='(')
                {
                    stk.pop();
                }
                stk.pop();
            }
        }
        else if(c=='(')
        {
            stk.push(c);
        }
    }
    
    return 0;
}
