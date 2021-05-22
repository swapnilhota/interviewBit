int Solution::solve(string A) {
    
    long long mod=10003;
    long long ans=0;
    
    for(int i=0; i<A.length(); i++)
    {
        char c = tolower(A[i]);
        
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        {
            ans += A.length()-i;
        }
    }
    
    return ans%mod;
    
}
