bool checkGrid(vector<string> A, int row, int col)
{
    char ch = A[row][col];
    
    int r = (row/3)*3;
    int c = (col/3)*3;
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(r+i == row && c+j == col)
            {
                continue;
            }
            if(A[r+i][c+j]==ch)
            {
                return false;
            }
        }
    }
    
    return true;
}

bool checkCol(vector<string> A, int row, int col)
{
    char ch = A[row][col];
    
    for(int i=0; i<A.size(); i++)
    {
        if(i==row)
        {
            continue;
        }
        if(A[i][col]==ch)
        {
            return false;
        }
    }
    
    return true;
}

bool checkRow(vector<string> A, int row, int col)
{
    char ch = A[row][col];
    
    for(int i=0; i<A[0].length(); i++)
    {
        if(i==col)
        {
            continue;
        }
        if(A[row][i]==ch)
        {
            return false;
        }
    }
    
    return true;
}

bool check(vector<string> A, int row, int col)
{
    bool a1 = checkRow(A, row, col);
    bool a2 = checkCol(A, row, col);
    bool a3 = checkGrid(A, row, col);
    
    return (a1*a2)*a3;
}

int Solution::isValidSudoku(const vector<string> &A) {
    
    for(int i=0; i<A.size(); i++)
    {
        for(int j=0; j<A[0].length(); j++)
        {
            if(A[i][j]=='.')
            {
                continue;
            }
            if(!check(A, i, j))
            {
                return 0;
            }
        }
    }
    
    return 1;
    
}
