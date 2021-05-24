int Solution::threeSumClosest(vector<int> &A, int B) {
    
    sort(A.begin(), A.end());
    
    int res=INT_MAX;
    int ans;
    
    for(int i=0; i<A.size()-2; i++)
    {
        int l=i+1;
        int r=A.size()-1;
        
        while(l<r)
        {
            long sum = (long)A[i] + (long)A[l] + (long)A[r];
            if(sum==B)
            {
                return sum;
            }
            if(sum<B)
            {
                l++;
            }
            else
            {
                r--;
            }
            if(abs(sum-B)<res)
            {
                res=abs(sum-B);
                ans=sum;
            }
        }
        
    }
    
    return ans;
    
}
