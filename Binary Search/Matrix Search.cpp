int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    
    int rows = A.size();
    int cols = A[0].size();
    
    int r;
    
    for(int i=0; i<rows; i++)
    {
        if(B>=A[i][0])
        {
            if(i==rows-1)
            {
                r=i;
                break;
            }
            if(B<A[i+1][0])
            {
                r=i;
                break;
            }
        }
    }
    
    int left=0;
    int right=cols-1;
    
    while(left<right)
    {
        int mid = (left+right)/2;
        if(A[r][mid]==B)
        {
            return 1;
        }
        if(B<A[r][mid])
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    
    if(A[r][left]==B)
    {
        return 1;
    }
    
    return 0;
    
}
