/*
Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.



Input Format:

The first and the only argument contains the string A.
Output Format:

Return an integer, representing the answer as described in the problem statement.
Constraints:

1 <= length(A) <= 501
*/

bool palindrome(string &A, int i, int j)
{
    while(i<j)
    {
        if(A[i]!=A[j]) return false;
        i++;
        j--;
    }

    return true;
}

int solve(string &A, int i, int j, vector<vector<int>> &dp)
{
    if(i>=j)
    {
        return 0;
    }
    if(palindrome(A, i, j))
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    int ans=INT_MAX;

    for(int k=i; k<j; k++)
    {
        int temp = solve(A, i, k, dp) + solve(A, k+1, j, dp) + 1;
        ans = min(temp, ans);
    }

    return dp[i][j] = ans;
}

int Solution::minCut(string A) {
    int n = A.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return solve(A, 0, n-1, dp);
}
