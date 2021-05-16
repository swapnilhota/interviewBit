#define M 1000003

long long factorial(long long x) {
    long long a[x+1];
    a[1] = 1;
    for(long long i=2; i<=x; i++) {
        a[i] = (i*a[i-1])%M;
    }
    return a[x];
}

int Solution::findRank(string A) {
    
    long long n = A.length();
    if(n==1 || n==0) {
        return 1;
    }
    
    long long ans = 0;
    
    for(long long i=n-2; i>=0; i--) {
        string temp = A.substr(i);
        sort(temp.begin(), temp.end());
        long long idx=i;
        for(long long j=0; j<temp.length(); j++) {
            if(temp[j]==A[i]) {
                idx=i+j;
                break;
            }
        }
        if(idx>i) {
            ans = (ans%M + ((idx-i)*factorial(n-i-1))%M)%M;
        }
    }
    
    ans++;
    
    return ans%M;
    
}
