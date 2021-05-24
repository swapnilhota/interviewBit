int Solution::divide(int A, int B) {
    
    if(A==INT_MIN && B==-1)
    {
        return INT_MAX;
    }
    
    long long a=A;
    long long b=B;
    
    long long sign = ((A<0)^(B<0)) ? -1:1;
    long long ans=0;
    
    a = abs(a);
    b = abs(b);
    
    while(a>=b)
    {
        a -= b;
        ans++;
    }
    
    return ans*sign;
    
}
