struct Term {
  int val;
  int idx;
};

bool compare(Term a, Term b) {
    return a.val < b.val;
}

int Solution::maximumGap(const vector<int> &A) {
    
    int n = A.size();
    
    if(n==1 || n==0) {
        return 0;
    }
    
    Term arr[n];
    
    for(int i=0; i<n; i++) {
        arr[i].val = A[i];
        arr[i].idx = i;
    }
    
    sort(arr, arr+n, compare);
    
    int maxArr[n];
    int minArr[n];
    
    maxArr[n-1] = arr[n-1].idx;
    minArr[0] = arr[0].idx;
    
    for(int i=1; i<n; i++) {
        minArr[i] = min(minArr[i-1], arr[i].idx);
        //cout << minArr[i] << " ";
    }
    //cout << endl;
    
    for(int i=n-2; i>=0; i--) {
        maxArr[i] = max(maxArr[i+1], arr[i].idx);
        //cout << maxArr[i] << " ";
    }
    //cout << endl;
    
    int ans = 0;
    
    for(int i=0; i<n; i++) {
        ans = max(ans, maxArr[i]-minArr[i]);
    }
    
    return ans;
}
