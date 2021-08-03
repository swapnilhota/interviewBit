/*
Problem Description

Given a string A, find the common palindromic sequence ( A sequence which does not need to be contiguous and is a pallindrome), which is common in itself.

You need to return the length of longest palindromic subsequence in A.

NOTE:

Your code will be run on multiple test cases (<=10). Try to come up with an optimised solution.


Problem Constraints
 1 <= |A| <= 1005



Input Format
First and only argument is an string A.



Output Format
Return a integer denoting the length of longest palindromic subsequence in A.



Example Input
Input 1:

 A = "bebeeed"


Example Output
Output 1:

 4


Example Explanation
Explanation 1:

 The longest common pallindromic subsequence is "eeee", which has a length of 4
*/

int dp[1008][1008];

int helper(string &A, int i, int j)
{
    if(i==j)
    {
        return 1;
    }
    if(j<i)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(A[i]==A[j])
    { 
        return dp[i][j] = (2 + helper(A, i+1, j-1));
    }
    else
    {
        return dp[i][j] = max(helper(A, i+1, j), helper(A, i, j-1));
    }
}

int Solution::solve(string A) {

    memset(dp, -1, sizeof(dp));
    int ans = helper(A, 0, A.length()-1);

    return ans;
}
