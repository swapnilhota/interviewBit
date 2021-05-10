vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    int flag=1;
    for(int i=n-1; i>0; i--) {
        if(A[i-1]<A[i]) {
            if(i<n-1) {
                int temp = A[i];
                int idx=i;
                for(int j=i+1; j<n; j++) {
                    if(A[j]>A[i-1]) {
                        if(A[j]<temp) {
                            temp=A[j];
                            idx=j;
                        }
                    }
                }
                swap(A[i-1], A[idx]);
                sort(A.begin()+i, A.end());
            }
            else {
                swap(A[i-1], A[i]);
            }
            flag=0;
            break;
        }
    }
    if(flag==1) {
        sort(A.begin(), A.end());
    }
    return A;
}
