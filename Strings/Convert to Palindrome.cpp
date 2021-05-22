bool check(string s)
{
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    if(tmp==s)
    {
        return true;
    }
    
    return false;
}

int Solution::solve(string A) {
    
    if(check(A))
    {
        if(A.length()%2==0)
        {
            return 0;
        }
        
        return 1;
    }
    
    string tmp = A;
    reverse(tmp.begin(), tmp.end());
    int idx;
    
    for(int i=0; i<A.length(); i++)
    {
        if(A[i]!=tmp[i])
        {
            idx=i;
            break;
        }
    }
    
    tmp = tmp.substr(0, idx)+tmp.substr(idx+1);
    A = A.substr(0, idx)+A.substr(idx+1);
    
    if(check(A) || check(tmp))
    {
        return 1;
    }
    
    return 0;
    
}
