bool check(vector<int> A, int B, int pages)
{
    int studs=1;
    int sum=0;
    
    for(auto i: A)
    {
        if(sum+i>pages)
        {
            sum=i;
            studs++;
            if(studs>B)
            {
                return false;
            }
        }
        else
        {
            sum += i;
        }
    }
    
    return true;
}

int Solution::books(vector<int> &A, int B) {
    
    if(B>A.size())
    {
        // not possible
        return -1;
    }
    
    int low=A[0];
    int high=0;
    
    int n = A.size();
    
    for(int i=0; i<n; i++)
    {
        high += A[i];
        low=max(low, A[i]);
    }
    
    // lowest max pages = low
    // highest possible max pages = high
    
    int ans=low;
    
    while(low<=high)
    {
        int mid = (high-low)/2 + low;
        
        if(check(A, B, mid))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    
    return ans;
    
}
