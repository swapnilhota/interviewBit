vector<vector<int> > Solution::generateMatrix(int A) {
    
    int x = 1;
    
    int top=0;
    int left=0;
    int right=A-1;
    int bottom=A-1;
    
    int arr[A][A];
    
    int flag=1;
    
    while(x<=A*A) {
        if(flag==1) {
            for(int i=left; i<=right; i++) {
                arr[top][i] = x;
                x++;
            }
            flag=2;
            top++;
        }
        if(flag==2) {
            for(int i=top; i<=bottom; i++) {
                arr[i][right] = x;
                x++;
            }
            flag=3;
            right--;
        }
        if(flag==3) {
            for(int i=right; i>=left; i--) {
                arr[bottom][i] = x;
                x++;
            }
            flag=4;
            bottom--;
        }
        if(flag==4) {
            for(int i=bottom; i>=top; i--) {
                arr[i][left] = x;
                x++;
            }
            flag=1;
            left++;
        }
    }
    
    vector<vector<int>> ans;
    
    for(int i=0; i<A; i++) {
        vector<int> row;
        for(int j=0; j<A; j++) {
            row.push_back(arr[i][j]);
        }
        ans.push_back(row);
    }
    
    return ans;
    
}
