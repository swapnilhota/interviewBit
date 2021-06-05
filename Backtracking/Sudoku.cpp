bool checkGrid(vector<vector<char>> B, int row, int col, int num)
{
    char ch = (char)('0'+num);
    
    int r = (row/3)*3;
    int c = (col/3)*3;
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if((r+i)==row && (c+j)==col)
            {
                continue;
            }
            if(B[r+i][c+j]==ch)
            {
                return false;
            }
        }
    }
    
    return true;
}

bool checkCol(vector<vector<char>> B, int row, int col, int num)
{
    char c = (char)('0'+num);
    
    for(int j=0; j<9; j++)
    {
        if(j==col)
        {
            continue;
        }
        if(B[row][j]==c)
        {
            return false;
        }
    }
    
    return true;
}

bool checkRow(vector<vector<char>> B, int row, int col, int num)
{
    char c = (char)('0'+num);
    
    for(int i=0; i<9; i++)
    {
        if(i==row)
        {
            continue;
        }
        if(B[i][col]==c)
        {
            return false;
        }
    }
    
    return true;
}

bool check(vector<vector<char>> B, int row, int col, int num)
{
    bool a1 = checkRow(B, row, col, num);
    bool a2 = checkCol(B, row, col, num);
    bool a3 = checkGrid(B, row, col, num);
    
    return a1*a2*a3;
}

void solve(vector<vector<char>> &A, vector<vector<char>> B, int row, int col)
{
    if(row==9)
    {
        A=B;
        return;
    }
    
    int nextRow;
    int nextCol;
    
    if(col==8)
    {
        nextRow=row+1;
        nextCol=0;
    }
    else
    {
        nextRow=row;
        nextCol=col+1;
    }
    
    if(B[row][col]!='.')
    {
        solve(A, B, nextRow, nextCol);
    }
    else
    {
        for(int i=1; i<10; i++)
        {
            if(check(B, row, col, i))
            {
                B[row][col] = (char)('0'+i);
                solve(A, B, nextRow, nextCol);
                B[row][col] = '.';
            }
        }
    }
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    
    vector<vector<char>> B = A;
    
    solve(A, B, 0, 0);
    
}
