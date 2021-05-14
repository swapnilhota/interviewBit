void Solution::setZeroes(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    
    set<int> rows;
    set<int> cols;
    
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(A[i][j]==0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    
    for(auto i=rows.begin(); i!=rows.end(); i++) {
        int row = *i;
        for(int col=0; col<n; col++) {
            A[row][col] = 0;
        }
    }
    
    for(auto i=cols.begin(); i!=cols.end(); i++) {
        int col = *i;
        for(int row=0; row<m; row++) {
            A[row][col] = 0;
        }
    }
}
