int Solution::solve(vector<int> &A, int B) {
    
    int left=0;
    int ones=0;
    int zeros=0;
    int res=0;
    
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]==1)
        {
            ones++;
        }
        else
        {
            zeros++;
        }
        
        while(zeros>B)
        {
            if(A[left]==1)
            {
                ones--;
            }
            else
            {
                zeros--;
            }
            left++;
        }
        
        res=max(res, i-left+1);
    }
    
    return res;
    
}
