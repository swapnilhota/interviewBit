bool check(vector<string> v, int n, int row, int col )
{
    if(row==0) return true;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]=='Q')
            {
                if(col==j || (abs(row-i)==1 && abs(col-j)==1) || abs(row-i)==abs(col-j)) 
                {
                    return false;
                }    
                
                break;
            }
        }
    }
    return true;
}

void get_queen(vector<vector<string> > &ans,vector<string> &v, int n, int row )
{
    if(row==n)
    {
        ans.push_back(v);
        return;
    }
    
    for(int col=0;col<n;col++)
    {
        
        if(check(v,n, row,col))
        {
            v[row][col]='Q';
            get_queen(ans,v,n,row+1);
            v[row][col]='.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string> > ans;
    vector<string> v(A,string(A,'.'));
    
    if(A==3 || A==2) return ans;
    
    get_queen(ans,v,A,0);
    return ans;
    
}
