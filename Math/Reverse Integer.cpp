int Solution::reverse(int A) {
    if(A>INT_MAX)
    {
        return 0;
    }
    if(A<INT_MIN)
    {
        return 0;
    }
    string s = to_string(A);
    string num = "";
    for(int i=s.length()-1; i>=0; i--)
    {
        num += s[i];
    }
    int ans;
    try
    {
        ans = stoi(num);    
    }
    catch(...)
    {
        return 0;
    }
    if(A<0)
    {
        ans = -1*ans;
    }
    
    return ans;
}
