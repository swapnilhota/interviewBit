/*
Problem Description

Given a set of N intervals denoted by 2D array A of size N x 2, the task is to find the length of maximal set of mutually disjoint intervals.

Two intervals [x, y] & [p, q] are said to be disjoint if they do not have any point in common.

Return a integer denoting the length of maximal set of mutually disjoint intervals.



Problem Constraints
1 <= N <= 105

1 <= A[i][0] <= A[i][1] <= 109
*/

int Solution::solve(vector<vector<int> > &A) {
    if(A.size()==0) return 0;
    sort(A.begin(), A.end());
    int cnt=1;
    vector<int> curr = A[0];
    for(int i=1; i<A.size(); i++)
    {
        if(curr[1]<A[i][0])
        {
            cnt++;
            curr = A[i];
        }
        else if(curr[1]>A[i][1])
        {
            curr = A[i];
        }
    }

    return cnt;
}
