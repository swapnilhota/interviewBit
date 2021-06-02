void helper(int A, vector<string> &v, string tmp, int cntOpen, int cntClose)
{
    if(cntClose==A)
    {
        v.push_back(tmp);
        return;
    }
    
    if(cntOpen==A)
    {
        helper(A, v, tmp+')', cntOpen, cntClose+1);
    }
    else
    {
        helper(A, v, tmp+'(', cntOpen+1, cntClose);
        helper(A, v, tmp+')', cntOpen, cntClose+1);
    }
}

bool check(string s)
{
    stack<char> stk;
    
    int cnt_open=0;
    int cnt_close=0;
    
    for(char c:s)
    {
        if(c=='(')
        {
            stk.push('(');
            cnt_open++;
        }
        else
        {
            if(stk.empty())
            {
                return false;
            }
            if(stk.top()=='(')
            {
                stk.pop();
            }
            else
            {
                return false;
            }
            cnt_close++;
        }
    }
    
    if(cnt_open!=cnt_close)
    {
        return false;
    }
    
    return true;
}

vector<string> Solution::generateParenthesis(int A) {
    
    string tmp="";
    vector<string> v;
    
    helper(A, v, tmp, 0, 0);
    
    vector<string> res;
    
    for(auto i:v)
    {
        if(check(i))
        {
            res.push_back(i);
        }
    }
    
    return res;
    
}
