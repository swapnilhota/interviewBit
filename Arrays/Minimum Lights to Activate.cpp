int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    
    int curr=0;
    int last=0;
    int cnt=0;
    
    bool flag=false;
    
    while(curr<n) {
        flag=false;
        int i = min(curr+B-1, n-1);
        while(i>= max(curr-B+1, last)) {
            if(A[i]==1) {
                last=i;
                cnt++;
                curr=i+B;
                flag=true;
                break;
            }
            i--;
        } 
        if(flag==false) {
            break;
        }
    }
    
    if(flag==false) {
        return -1;
    }
    
    return cnt;
    
}
