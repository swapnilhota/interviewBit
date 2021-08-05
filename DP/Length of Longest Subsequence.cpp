/*
Problem Description

Given an 1D integer array A of length N, find the length of longest subsequence which is first increasing then decreasing.



Problem Constraints
0 <= N <= 3000

 -107 <= A[i] <= 107



Input Format
The first and the only argument contains an integer array A.



Output Format
Return an integer representing the answer as described in the problem statement.



Example Input
Input 1:

 A = [1, 2, 1]
Input 2:

 A = [1, 11, 2, 10, 4, 5, 2, 1]


Example Output
Output 1:

 3
Output 2:

 6


Example Explanation
Explanation 1:

 [1, 2, 1] is the longest subsequence.
Explanation 2:

 [1 2 10 4 2 1] is the longest subsequence.
*/

int Solution::longestSubsequenceLength(const vector<int> &A) {

    int n = A.size();
    vector<int> dp_inc(n+1, 1);
    vector<int> dp_dec(n+1, 1);

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(A[j]<A[i])
            {
                dp_inc[i] = max(dp_inc[i], 1+dp_inc[j]);
            }
        }
    }

    for(int i=n-2; i>=0; i--)
    {
        for(int j=n-1; j>i; j--)
        {
            if(A[i]>A[j])
            {
                dp_dec[i] = max(dp_dec[i], 1+dp_dec[j]);
            }
        }
    }

    int ans=0;

    for(int i=0; i<n; i++)
    {
        ans = max(ans, dp_inc[i]+dp_dec[i]-1);
    }

    return ans;

}
