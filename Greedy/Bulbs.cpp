/*
N light bulbs are connected by a wire.

Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb.

Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.

You can press the same switch multiple times.

Note : 0 represents the bulb is off and 1 represents the bulb is on.



Input Format:

The first and the only argument contains an integer array A, of size N.

Output Format:

Return an integer representing the minimum number of switches required.

Constraints:

1 <= N <= 5e5

0 <= A[i] <= 1
*/

int Solution::bulbs(vector<int> &A) {
    int chg=0;

    for(auto i: A)
    {
        if(i==0)
        {
            if(chg%2==0)
            {
                chg++;
            }
        }
        else
        {
            if(chg%2!=0)
            {
                chg++;
            }
        }
    }

    return chg;
}
