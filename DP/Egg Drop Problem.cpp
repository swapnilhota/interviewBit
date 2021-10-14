/*
Problem Description

You are given A eggs, and you have access to a building with B floors from 1 to B.

Each egg is identical in function, and if an egg breaks, you cannot drop it again.

You know that there exists a floor C with 0 <= C <= B such that any egg dropped at a floor higher than C will break, and any egg dropped at or below floor C will not break.

Each move, you may take an egg (if you have an unbroken one) and drop it from any floor X (with 1 <= X <= B).

Your goal is to know with certainty what the value of C is.

What is the minimum number of moves that you need to know with certainty what C is, regardless of the initial value of C
*/

int Solution::solve(int A, int B) {
    int dp[A+1][B+1];
    for(int i=1; i<=A; i++)
    {
        for(int j=0; j<=B; j++)
        {
            if(i==1)
            {
                dp[i][j] = j;
            }
            if(j==0 || j==1)
            {
                dp[i][j] = j;
            }
        }
    }

    for(int i=2; i<=A; i++)
    {
        for(int j=2; j<=B; j++)
        {
            int low=1;
            int high=j;
            int ans=INT_MAX;
            while(low<=high)
            {
                int mid = (high-low)/2+low;
                int left = dp[i-1][mid-1];
                int right = dp[i][j-mid];
                ans = min(ans, 1+max(left, right));
                if(left>right) high=mid-1;
                else low = mid+1;
            }
            dp[i][j] = ans;
        }
    }

    return dp[A][B];
}
