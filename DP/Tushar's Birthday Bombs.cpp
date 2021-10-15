/*
Problem Description

It’s Tushar’s birthday today and he has N friends.

Friends are numbered [0, 1, 2, ...., N-1] and ith friend have a positive strength B[i].

Today being his birthday, his friends have planned to give him birthday bombs (kicks).

Tushar's friends know Tushar's pain bearing limit and would hit accordingly.

If Tushar’s resistance is denoted by A (>=0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative kick strength (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of kicks hit are maximum.

Also note that each friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times)

Return the lexicographically smallest array of maximum length where the ith index represents the index of the friend who will hit.
*/

vector<int> Solution::solve(int A, vector<int> &B) {
    int minStrength = *min_element(B.begin(), B.end());

    int i=0;

    vector<int> res;

    while(i<B.size() && A>0)
    {
        if(B[i]<=A)
        {
            int kicksAfter = (A-B[i])/minStrength;
            int kicksNow = (A-minStrength)/minStrength;

            if(kicksAfter==kicksNow)
            {
                res.push_back(i);
                A -= B[i];
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }

    return res;
}
