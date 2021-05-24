#define mod 1000000007

int Solution::cntBits(vector<int> &A) {
    
    int n = A.size();
    
    long long ans = 0;
    
    for(int i=0; i<32; i++)
    {
        long long cnt_zeroes = 0;
        for(int j=0; j<n; j++)
        {
            if((A[j]&(1<<i))==0)
            {
                cnt_zeroes++;
            }
        }
        
        long long cnt_ones = n-cnt_zeroes;
        
        ans += ((cnt_ones%mod)*(cnt_zeroes%mod))%mod;
    }
    
    return (2*ans)%mod;
    
}
