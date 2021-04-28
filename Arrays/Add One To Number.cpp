vector<int> Solution::plusOne(vector<int> &A) {
    
    int carry = 0;
    
    int n = A.size();
    
    int x = A[n-1]+1;
    
    A[n-1] = x%10;
    
    carry = x/10;
    
    for(int i=n-2; i>=0; i-- ) {
        
        int x = A[i]+carry;
        A[i] = x%10;
        carry = x/10;
        
    }
    
    vector<int> ans;
    
    if(carry>0) {
        ans.push_back(carry);
    }
    
    int i=0;
    
    while(i<n && A[i]==0) {
        i++;
    }
    
    if(i==n) {
        i=0;
    }
    
    for(; i<n; i++) {
        ans.push_back(A[i]);
    }
    
    return ans;
    
}
