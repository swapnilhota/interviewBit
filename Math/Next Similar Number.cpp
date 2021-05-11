string Solution::solve(string A) {
    set<char> s;
    int n = A.length();
    int flag=0;
    for(int i=n-2; i>=0; i--) {
        if(A[i]<A[i+1]) {
            int temp = A[i+1];
            int idx = i+1;
            for(int j=i+1; j<n; j++) {
                if(A[j]>A[i]) {
                    if(A[j]<temp) {
                        temp=A[j];
                        idx=j;
                    }
                }
            }
            swap(A[i], A[idx]);
            sort(A.begin()+i+1, A.end());
            flag=1;
            break;
        }
    }
    
    if(flag==0) {
        return "-1";
    }
    
    return A;
}
