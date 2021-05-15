int Solution::solve(vector<vector<int> > &A, int B) {
    
    int n = A.size();
    
    if(B==1) {
        int sum = INT_MIN;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                sum = max(sum, A[i][j]);
            }
        }
        return sum;
    }
    
    if(B==n) {
        int sum = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                sum += A[i][j];
            }
        }
        return sum;
    }
    
    
    
    for(int i=0; i<n; i++) {
        for(int j=1; j<n; j++) {
            A[i][j] += A[i][j-1];
        }
    }
    
    vector<vector<int>> t = A;
    
    for(int i=0; i<n; i++) {
        for(int j=B; j<n; j++) {
            t[i][j] = A[i][j]-A[i][j-B];
        }
    }
    
    for(int j=B-1; j<n; j++) {
        for(int i=1; i<n; i++) {
            t[i][j] += t[i-1][j];
        }
    }
    
    A = t;
    
    for(int j=B-1; j<n; j++) {
        for(int i=B; i<n; i++) {
            A[i][j] = t[i][j] - t[i-B][j];
        }
    }
    
    int ans = INT_MIN;
    
    for(int i=B-1; i<n; i++) {
        for(int j=B-1; j<n; j++) {
            ans = max(ans, A[i][j]);
            //cout << A[i][j] << " ";
        }
        //cout << endl;
    }
    
    return ans;
    
}
