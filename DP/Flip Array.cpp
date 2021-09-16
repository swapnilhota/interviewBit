/*
Given an array of  positive elements, you have to flip the sign of some of its elements such that the resultant sum of the elements of array should be minimum non-negative(as close to zero as possible). Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.

Constraints:

 1 <= n <= 100
Sum of all the elements will not exceed 10,000.

Example:

A = [15, 10, 6]
ans = 1 (Here, we will flip the sign of 15 and the resultant sum will be 1 )

A = [14, 10, 4]
ans = 1 (Here, we will flip the sign of 14 and the resultant sum will be 0)

Note that flipping the sign of 10 and 4 also gives the resultant sum 0 but flippings there are not minimum
*/

int helper(const vector<int> &A, int n, int total, vector<vector<int>> &dp)
{
    if(total==0)
    {
        return 0;
    }
    if(n==0)
    {
        return total;
    }
    if(dp[n][total]!=-1)
    {
        return dp[n][total];
    }
    if(total >= 2*A[n-1])
    {
        return dp[n][total] = min(helper(A, n-1, total-2*A[n-1], dp), helper(A, n-1, total, dp));
    }
    else
    {
        return dp[n][total] = helper(A, n-1, total, dp);
    }
}

int helper2(const vector<int> &A, int n, int total, int minTotal, vector<vector<int>> &dp)
{
    if(total==minTotal)
    {
        return 0;
    }
    if(n==0 && total==minTotal)
    {
        return 0;
    }
    if(n==0)
    {
        return INT_MAX-1;
    }
    if(dp[n][total]!=-1)
    {
        return dp[n][total];
    }

    if(total >= 2*A[n-1])
    {
        return dp[n][total] = min(1+helper2(A, n-1, total-2*A[n-1], minTotal, dp), helper2(A, n-1, total, minTotal, dp));
    }
    else
    {
        return dp[n][total] = helper2(A, n-1, total, minTotal, dp);
    }
}

int Solution::solve(const vector<int> &A) {
    int total=0;
    for(auto i: A)
    {
        total+=i;
    }

    vector<vector<int>> dp1(A.size()+1, vector<int>(total+1, -1));
    vector<vector<int>> dp2(A.size()+1, vector<int>(total+1, -1));

    int minTotal = helper(A, A.size(), total, dp1);

    int minChg = helper2(A, A.size(), total, minTotal, dp2);

    return minChg;
}
