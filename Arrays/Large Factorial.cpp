string Solution::solve(int A) {
    
    string ans = "1";
    
    for(int i=2; i<=A; i++) {
        int carry=0;
        for(int j=0; j<ans.length(); j++) {
            int x = (ans[j]-'0')*i + carry;
            carry = x/10;
            ans[j] = '0' + x%10;
        }
        if(carry>0) {
            string temp = to_string(carry);
            reverse(temp.begin(), temp.end());
            ans = ans+temp;
        }
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
    
}
