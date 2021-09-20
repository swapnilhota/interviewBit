/*
Problem Description

Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.

You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Input Format:

The first and the only argument is an array of integer, A.

Output Format:

Return an integer, representing the maximum possible profit.

Constraints:

0 <= len(A) <= 1e5
1 <= A[i] <= 1e7
*/

int Solution::maxProfit(const vector<int> &A) {
    if(A.size()==0)
    {
        return 0;
    }
    int ans=0;
    int cp=A[0];
    for(auto p: A)
    {
        if(p<cp)
        {
            cp=p;
        }
        else
        {
            ans += p-cp;
            cp=p;
        }
    }
    return ans;
}
