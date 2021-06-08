string Solution::fractionToDecimal(int A, int B) {
    
    long long a = (long long)A;
    long long b = (long long)B;
    
    string intPart=to_string(abs(a/b));
    
    if(A<0 && B>0 || A>0 && B<0)
    {
        intPart = "-"+intPart;
    }
    
    a = abs(a);
    b = abs(b);
    
    string fracPart="";
    
    long long rem=abs(a%b);
    
    map<long long, long long> mp;
    int flag=0;
    
    int i=1;
    
    while(rem!=0)
    {
        rem *= 10LL;
        if(mp[rem]>0)
        {
            flag=1;
            break;
        }
        mp[rem] = i;
        fracPart += to_string(rem/b);
        rem = rem%b;
        i++;
    }
    
    if(fracPart=="")
    {
        return intPart;
    }
    
    string ans="";
    
    if(flag==1)
    {
        fracPart = fracPart.substr(0, mp[rem]-1)+"("+fracPart.substr(mp[rem]-1)+")";
    }
    
    ans += intPart+"."+fracPart;
    
    return ans;
}
