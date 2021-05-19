int Solution::solve(vector<int> &A, int B) {
    
    int idx=A.size();
    int left=0;
    int right=A.size()-1;
    
    while(left<right)
    {
        int mid = (left+right)/2;
        
        if(A[mid]==B)
        {
            return mid;
        }
        
        if(A[mid]>A[mid+1])
        {
            idx=min(idx, mid);
        }
        
        if(B>A[mid])
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    
    if(A[left]==B)
    {
        return left;
    }
    
    if(idx==A.size())
    {
        return -1;
    }
    
    left=idx;
    right=A.size()-1;
    
    while(left<right)
    {
        int mid = (left+right)/2;
        
        if(A[mid]==B)
        {
            return mid;
        }
        
        if(B<A[mid])
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    
    if(A[left]==B)
    {
        return left;
    }
    
    return -1;
    
}
