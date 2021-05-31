int Solution::solve(vector<int> &A, int B, int C) {
    
    int ans=0;
    
    int n = A.size();
    
    for(int i=0; i<n; i++)
    {
        int cntB=0;
        int cntC=0;
        
        for(int j=i; j<n; j++)
        {
            if(A[j]==B)
            {
                cntB++;
            }
            else if(A[j]==C)
            {
                cntC++;
            }
            if(cntB==cntC)
            {
                ans++;
            }
        }
    }
    
    return ans;
    
}
