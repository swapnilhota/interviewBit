/*
Problem Description

Say you have an array, A, for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Return the maximum possible profit.
*/

int Solution::maxProfit(const vector<int> &A) {
    int ans = 0;
    if(A.size()==0) return ans;
    int minTerm = A[0];
    for(int i=1; i<A.size(); i++)
    {
        ans = max(ans, A[i]-minTerm);
        minTerm = min(minTerm, A[i]);
    }
    return ans;
}
