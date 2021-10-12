/*
Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values 1…A?

Input Format:

The first and the only argument of input contains the integer, A.
Output Format:

Return an integer, representing the answer asked in problem statement.
Constraints:

1 <= A <= 18
*/

int dp[20][20];

int solve(int A, int left, int right)
{
    if(left>right)
    {
        return 1;
    }
    if(left>=right)
    {
        return 1;
    }
    if(dp[left][right]!=-1)
    {
        return dp[left][right];
    }

    int ans = 0;

    for(int i=left; i<=right; i++)
    {
        ans += solve(A, left, i-1)*solve(A, i+1, right);
    }

    return dp[left][right] = ans;
}

int Solution::numTrees(int A) {
    if(A==1)
    {
        return 1;
    }
    int ans=0;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=A; i++)
    {
        ans += solve(A, 1, i-1)*solve(A, i+1, A);
    }
    return ans;
}
