/*
There is a rectangle with left bottom as  (0, 0) and right up as (x, y). There are N circles such that their centers are inside the rectangle.

Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note :  We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.




Input Format

1st argument given is an Integer x.
2nd argument given is an Integer y.
3rd argument given is an Integer N, number of circles.
4th argument given is an Integer R, radius of each circle.
5th argument given is an Array A of size N, where A[i] = x cordinate of ith circle
6th argument given is an Array B of size N, where B[i] = y cordinate of ith circle
Output Format

Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).
*/

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int r, int c)
{
    vis[r][c]=true;
    if(grid[r][c]==1)
    {
        return;
    }
    for(int k=0; k<8; k++)
    {
        int i = r+dy[k]; int j = c+dx[k];
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size())
        {
            if(!vis[i][j] && grid[i][j]!=1)
            {
                dfs(grid, vis, i, j);
            }
        }
    }
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int>> grid(A+1, vector<int>(B+1, 0));
    
    for(int i=0; i<=A; i++)
    {
        for(int j=0; j<=B; j++)
        {
            for(int k=0; k<E.size(); k++)
            {
                if(sqrt(pow(E[k]-i, 2) + pow(F[k]-j, 2))<=D)
                {
                    grid[i][j] = 1;
                }
            }
        }
    }

    vector<vector<bool>> vis(A+1, vector<bool>(B+1, false));

    dfs(grid, vis, 0, 0);

    if(vis[A][B]) return "YES";

    return "NO";
}
