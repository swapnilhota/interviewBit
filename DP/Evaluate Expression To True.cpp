/*
Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

Operands are only true and false.

Return the number of ways to evaluate the expression modulo 103 + 3.



Input Format:

The first and the only argument of input will contain a string, A.

The string A, may contain these characters:
    '|' will represent or operator 
    '&' will represent and operator
    '^' will represent xor operator
    'T' will represent true operand
    'F' will false
Output:

Return an integer, representing the number of ways to evaluate the string.
Constraints:

1 <= length(A) <= 150
Example:

Input 1:
    A = "T|F"

Output 1:
    1

Explanation 1:
    The only way to evaluate the expression is:
        => (T|F) = T 

Input 2:
    A = "T^T^F"
    
Output 2:
    0
    
Explanation 2:
    There is no way to evaluate A to a true statement.
*/

const int M = 1e3+3;

int solve(string A, int i, int j, bool isTrue, vector<vector<vector<int>>> &dp)
{
    if(i>j)
    {
        return false;
    }
    if(i==j)
    {
        if(isTrue)
        {
            return A[i]=='T';
        }
        else
        {
            return A[i]=='F';
        }
    }
    if(dp[i][j][isTrue]!=-1)
    {
        return dp[i][j][isTrue];
    }

    int ans=INT_MIN;

    if(isTrue)
    {
        int temp=0;
        for(int k=i+1; k<=j-1; k++)
        {
            
            if(A[k]=='|')
            {
                int a1 = solve(A, i, k-1, true, dp)*solve(A, k+1, j, true, dp);
                int a2 = solve(A, i, k-1, true, dp)*solve(A, k+1, j, false, dp);
                int a3 = solve(A, i, k-1, false, dp)*solve(A, k+1, j, true, dp);

                temp += (a1+a2+a3)%M;
            }
            else if(A[k]=='&')
            {
                int a1 = solve(A, i, k-1, true, dp)*solve(A, k+1, j, true, dp);
                temp += a1%M;
            }
            else
            {
                int a1 = solve(A, i, k-1, true, dp)*solve(A, k+1, j, false, dp);
                int a2 = solve(A, i, k-1, false, dp)*solve(A, k+1, j, true, dp);
                temp += (a1+a2)%M;
            }
        }
        ans = max(ans, temp);
    }
    else
    {
        int temp=0;
        for(int k=i+1; k<=j-1; k+=2)
        {
            
            if(A[k]=='|')
            {
                int a1 = solve(A, i, k-1, false, dp)*solve(A, k+1, j, false, dp);
                temp += a1%M;
            }
            else if(A[k]=='&')
            {
                int a1 = solve(A, i, k-1, false, dp)*solve(A, k+1, j, false, dp);
                int a2 = solve(A, i, k-1, true, dp)*solve(A, k+1, j, false, dp);
                int a3 = solve(A, i, k-1, false, dp)*solve(A, k+1, j, true, dp);
                temp += (a1+a2+a3)%M;
            }
            else if(A[k]=='^')
            {
                int a1 = solve(A, i, k-1, true, dp)*solve(A, k+1, j, true, dp);
                int a2 = solve(A, i, k-1, false, dp)*solve(A, k+1, j, false, dp);
                temp += (a1+a2)%M;
            }
            
        }
        ans = max(ans, temp);
    }

    return dp[i][j][isTrue] = ans;
}

int Solution::cnttrue(string A) {
    vector<vector<vector<int>>> dp(A.length()+1, vector(A.length()+1, vector<int>(2, -1)));
    return solve(A, 0, A.length()-1, true, dp)%M;
}
