vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    int n = A.size();
    int m = A[0].size();
    
    vector<vector<int>> ans;
    
    for(int i=0; i<m; i++)
    {
        int row = 0;
        int col = i;
        vector<int> diag;
        while(row<n && col>=0)
        {
            diag.push_back(A[row][col]);
            row++;
            col--;
        }
        ans.push_back(diag);
    }
    
    for(int i=1; i<n; i++)
    {
        int row = i;
        int col = m-1;
        vector<int> diag;
        while(row<n && col>=0)
        {
            diag.push_back(A[row][col]);
            row++;
            col--;
        }
        ans.push_back(diag);
    }
    
    return ans;
    
}
