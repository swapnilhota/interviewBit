string Solution::addBinary(string A, string B) {
    
    if(A.length()<B.length())
    {
        return addBinary(B, A);
    }
    
    string ans="";
    
    int i=A.length()-1;
    int j=B.length()-1;
    
    int carry=0;
    
    while(i>=0 && j>=0)
    {
        int x = (A[i]-'0')+(B[j]-'0')+carry;
        carry = x/2;
        x = x%2;
        ans += (char)('0'+x);
        i--;
        j--;
    }
    
    while(i>=0)
    {
        int x = (A[i]-'0') + carry;
        carry = x/2;
        x = x%2;
        ans += (char)('0'+x);
        i--;
    }
    
    if(carry>0)
    {
        ans += (char)('0'+carry);
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
    
}
