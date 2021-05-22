int Solution::solve(int A) {
    
    int ans=0;
    
    for(int i=0; i<32; i++)
    {
        if((A&(1<<i))==0)
        {
            ans++;
        }
        else
        {
            break;
        }
    }
    
    return ans;
    
}
