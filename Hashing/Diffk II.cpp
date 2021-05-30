int Solution::diffPossible(const vector<int> &A, int B) {
    
    map<int, int> m;
    
    for(int i:A)
    {
        m[i]++;
    }
    
    for(int i:A)
    {
        if(B==0)
        {
            if(m[i]>1)
            {
                return 1;
            }
        }
        else
        {
            if(m[i+B] || m[i-B])
            {
                return 1;
            }
        }
    }
    
    return 0;
    
}
