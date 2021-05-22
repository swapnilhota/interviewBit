int Solution::singleNumber(const vector<int> &A) {
    
    int ans=0;
    
    for(int i:A)
    {
        ans = ans^i;
    }
    
    return ans;
    
}
