vector<int> Solution::searchRange(const vector<int> &A, int B) {
    
    int l;
    int r;
    l=-1;
    r=-1;
    
    int left=0;
    int right=A.size()-1;
    
    while(left<right)
    {
        if(A[left]==B && A[right]==B)
        {
            l=left;
            r=right;
            break;
        }
        int mid = (left+right)/2;
        if(A[mid]==B)
        {
            l=mid;
            r=mid;
            break;
        }
        if(B<A[mid])
        {
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    
    if(l==-1)
    {
        if(A[left]==B)
        {
            l=r=left;
        }
        else
        {
            vector<int> ans = {-1, -1};
            return ans;
        }
    }
    
    for(int i=l; i>=0; i--)
    {
        if(A[i]!=B)
        {
            break;
        }
        
        l = min(l, i);
        
    }
    
    for(int i=r; i<A.size(); i++)
    {
        if(A[i]!=B)
        {
            break;
        }
        
        r=max(r, i);
    }
    
    vector<int> ans = {l, r};
    return ans;
    
}
