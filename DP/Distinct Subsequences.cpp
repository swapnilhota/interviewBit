/*
Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).

Input Format:

The first argument of input contains a string, A.
The second argument of input contains a string, B.
Output Format:

Return an integer representing the answer as described in the problem statement.
Constraints:

1 <= length(A), length(B) <= 700
*/

int dp[702][702];

int helper(string &A, string &B, int lenA, int lenB)
{
    if(lenA==0 && lenB==0)
    {
        return 1;
    }
    else if(lenA==0)
    {
        return 0;
    }
    else if(lenB==0)
    {
        return 1;
    }
    if(dp[lenA][lenB]!=-1)
    {
        return dp[lenA][lenB];
    }
    if(A[lenA-1]==B[lenB-1])
    {
        return dp[lenA][lenB] = helper(A, B, lenA-1, lenB-1) + helper(A, B, lenA-1, lenB);
    }
    else
    {
        return dp[lenA][lenB] = helper(A, B, lenA-1, lenB);
    }
}

int Solution::numDistinct(string A, string B) {
    memset(dp, -1, sizeof(dp));
    return helper(A, B, A.length(), B.length());
}
