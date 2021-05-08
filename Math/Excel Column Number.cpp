int Solution::titleToNumber(string A) {
    int p = 0;
    int ans = 0;
    int n = A.length();
    
    for(int i=n-1; i>=0; i--)
    {
        int x = A[i]-'A'+1;
        ans += x*(int)pow(26, p);
        p++;
    }
    
    return ans;
}
