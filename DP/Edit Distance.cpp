/*
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer, representing the minimum number of steps required.
Constraints:

1 <= length(A), length(B) <= 450
Examples:

Input 1:
    A = "abad"
    B = "abac"

Output 1:
    1

Explanation 1:
    Operation 1: Replace d with c.

Input 2:
    A = "Anshuman"
    B = "Antihuman"

Output 2:
    2

Explanation 2:
    => Operation 1: Replace s with t.
    => Operation 2: Insert i.
*/
int dp[410][410];

int helper(string &A, string &B, int n1, int n2)
{
    if(n1==0 || n2==0)
    {
        if(n1==n2)
        {
            return 0;
        }

        return max(n1, n2);
    }
    if(dp[n1][n2]!=-1)
    {
        return dp[n1][n2];
    }
    if(A[n1-1]==B[n2-1])
    {
        return dp[n1][n2] = helper(A, B, n1-1, n2-1);
    }
    else
    {
        int a1 = 1+helper(A, B, n1-1, n2-1);
        int a2 = 1+helper(A, B, n1-1, n2);
        int a3 = 1+helper(A, B, n1, n2-1);

        return dp[n1][n2] = min(a1, min(a2, a3));
    }
}

int Solution::minDistance(string A, string B) {
    memset(dp, -1, sizeof(dp));
    return helper(A, B, A.length(), B.length());
}
