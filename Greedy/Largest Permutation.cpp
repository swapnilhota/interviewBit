/*
Problem Description

Given an integer array A of size N consisting of unique integers from 1 to N. You can swap any two integers atmost B times.

Return the largest lexicographical value array that can be created by executing atmost B swaps.



Problem Constraints
1 <= N <= 106

1 <= B <= 109



Input Format
First argument is an integer array A of size N.

Second argument is an integer B.



Output Format
Return an integer array denoting the largest lexicographical value array that can be created by executing atmost B swaps.
*/
vector<int> Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    for(int i=0; i<A.size(); i++)
    {
        mp[A[i]] = i;
    }

    int N = A.size();

    if(B>=A.size())
    {
        sort(A.begin(), A.end(), greater<int>());
        return A;
    }

    for(int i=0; i<A.size(); i++)
    {
        if(B==0) break;

        if(A[i]!=(N-i))
        {
            int temp = A[i];
            int idx = mp[N-i];
            swap(A[idx], A[i]);
            B--;
            mp[N-i] = i;
            mp[temp] = idx;
        }
    }

    return A;
}
