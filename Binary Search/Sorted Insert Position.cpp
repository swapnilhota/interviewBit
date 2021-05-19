int Solution::searchInsert(vector<int> &A, int B) {
    
    int ans=0;
    
    int left=0;
    int right=A.size();
    
    while(left<right)
    {
        int mid = (left+right)/2;
        
        if(A[mid]==B)
        {
            return mid;
        }
        
        if(A[mid]<B)
        {
            left=mid+1;
        }
        else
        {
            right=mid-1;
            ans=mid;
        }
    }
    
    if(A[left]==B)
    {
        return left;
    }
    
    if(A[left]>B)
    {
        ans=left;
    }
    
    return ans;
    
}
