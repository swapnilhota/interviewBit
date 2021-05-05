int Solution::maxArr(vector<int> &A) {
    
    int n = A.size();
    
    int maxIdx=0;
    
    for(int i=1; i<n; i++)
    {
        if(A[i]>A[maxIdx])
        {
            maxIdx = i;
        }
        else
        {
            if(abs(i-maxIdx)>abs(A[i]-A[maxIdx]))
            {
                maxIdx=i;
            }
        }
    }
    
    int minIdx=n-1;
    
    for(int i=n-2; i>=0; i--)
    {
        if(A[i]<A[minIdx])
        {
            minIdx = i;
        }
        else
        {
            if(abs(i-minIdx)>abs(A[i]-A[minIdx]))
            {
                minIdx = i;
            }
        }
    }
    
    int ans1 = abs(A[maxIdx]-A[minIdx]) + abs(maxIdx-minIdx);
    
    minIdx=0;
    
    for(int i=1; i<n; i++)
    {
        if(A[i]>A[minIdx])
        {
            if(abs(i-minIdx)>abs(A[i]-A[minIdx]))
            {
                minIdx=i;
            }
        }
        else
        {
            minIdx = i;
        }
    }
    
    maxIdx=n-1;
    
    for(int i=n-2; i>=0; i--)
    {
        if(A[i]<A[maxIdx])
        {
            if(abs(i-maxIdx)>abs(A[i]-A[maxIdx]))
            {
                maxIdx = i;
            }
        }
        else
        {
            maxIdx=i;
        }
    }
    
    int ans2 = abs(A[maxIdx]-A[minIdx]) + abs(maxIdx-minIdx);
    
    return max(ans1, ans2);
    
}
