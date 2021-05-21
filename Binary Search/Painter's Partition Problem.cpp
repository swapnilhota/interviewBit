#define M 10000003

bool check(vector<int> C, int A, int mid)
{
    long long sum=0;
    int cnt=1;
    
    for(int i:C)
    {
        if(sum+i > mid)
        {
            sum = i;
            cnt++;
            
            if(cnt>A)
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

int Solution::paint(int A, int B, vector<int> &C) {
    
    int n = C.size();
    
    int maxLen = 0;
    
    long long high=0;
    
    for(int i : C)
    {
        maxLen = max(maxLen, i);
        high += i;
    }
    
    if(A>=n)
    {
        return (maxLen*B)%M;
    }
    
    long long low = maxLen;
    
    long long ans = low;
    
    while(low<=high)
    {
        long long mid = (high-low)/2 + low;
        
        if(check(C, A, mid))
        {
            ans = mid;
            high = mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    
    return ((ans%M)*(B%M))%M;
    
}
