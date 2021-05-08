string Solution::convertToTitle(int A) {
    int x = A;
    string ans = "";
    while(x>26)
    {
        int rem = x%26;
        x = x/26;
        if(rem==0)
        {
            ans += 'Z';
            x--;
        }
        else
        {
            ans += (char)('A'+rem-1);    
        }
    }
    if(x>0)
    {
        ans += (char)('A'+x-1);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
