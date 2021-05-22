string Solution::solve(string A, int B) {
    
    string ans="";
    
    char curr_char = A[0];
    int curr_cnt = 1;
    
    string temp="";
    temp += curr_char;
    
    for(int i=1; i<A.length(); i++)
    {
        if(A[i]!=curr_char)
        {
            if(curr_cnt!=B)
            {
                ans += temp;
            }
            temp=A[i];
            curr_char=A[i];
            curr_cnt=1;
        }
        else
        {
            curr_cnt++;
            temp += A[i];
        }
    }
    
    if(temp!="")
    {
        if(curr_cnt!=B)
        {
            ans+=temp;
        }
    }
    
    return ans;
    
}
