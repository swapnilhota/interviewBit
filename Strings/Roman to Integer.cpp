int Solution::romanToInt(string A) {
    
    if(A=="")
    {
        return 0;
    }
    
    map<char, int> m;
    
    m['M']=1000;
    m['D']=500;
    m['C']=100;
    m['L']=50;
    m['X']=10;
    m['V']=5;
    m['I']=1;
    
    int ans = m[A[A.length()-1]];
    char prev = A[A.length()-1]; 
    
    for(int i=A.length()-2; i>=0; i--)
    {
        if(m[A[i]] < m[prev])
        {
            ans -= m[A[i]];
            prev = A[i];
        }
        else
        {
            ans += m[A[i]];
            prev=A[i];
        }
    }
    
    return ans;
    
}
