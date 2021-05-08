int Solution::solve(int A, int B) {
    int ans = 0;
    int row = A;
    int col = B;
    
    while(row>0 && col>0)
    {
        row--;
        col--;
        ans++;
    }
    
    row=A;
    col=B;
    
    while(row>0 && col<9)
    {
        row--;
        col++;
        ans++;
    }
    
    row=A;
    col=B;
    
    while(row<9 && col>0)
    {
        row++;
        col--;
        ans++;
    }
    
    row=A;
    col=B;
    
    while(row<9 && col<9)
    {
        row++;
        col++;
        ans++;
    }
    
    return ans-4;
}
