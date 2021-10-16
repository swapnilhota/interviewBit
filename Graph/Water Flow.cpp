/*
Problem Description

Given an N x M matrix A of non-negative integers representing the height of each unit cell in a continent, the "Blue lake" touches the left and top edges of the matrix and the "Red lake" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the number of cells from where water can flow to both the Blue and Red lake.



Problem Constraints
1 <= M, N <= 1000

1 <= A[i][j] <= 109



Input Format
First and only argument is a 2D matrix A.



Output Format
Return an integer denoting the number of cells from where water can flow to both the Blue and Red lake.
*/

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void dfs(vector<vector<int> > &A, vector<vector<bool>> &vis, int r, int c)
{
    vis[r][c] = true;
    
    for(int k=0; k<4; k++)
    {
        int i = r+dx[k]; int j = c+dy[k];
        if(i>=0 && i<A.size() && j>=0 && j<A[0].size() && !vis[i][j] && A[i][j]>=A[r][c])
        {
            dfs(A, vis, i, j);
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<bool>> b(m, vector<bool>(n, false));
    vector<vector<bool>> r(m, vector<bool>(n, false));

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 && !b[i][j])
            {
                dfs(A, b, i, j);
            }
            if(j==0 && !b[i][j])
            {
                dfs(A, b, i, j);
            }
            if(i==m-1 && !r[i][j])
            {
                dfs(A, r, i, j);
            }
            if(j==n-1 && !r[i][j])
            {
                dfs(A, r, i, j);
            }
        }
    }

    int ans=0;

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(r[i][j] && b[i][j])
            {
                ans++;
            }
        }
    }

    return ans;
}
