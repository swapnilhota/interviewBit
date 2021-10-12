/*
Given a string A and a dictionary of words B, add spaces in A to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

Note : Make sure the strings are sorted in your result.

Input Format:

The first argument is a string, A.
The second argument is an array of strings, B.
Output Format:

Return a vector of strings representing the answer as described in the problem statement.
Constraints:

1 <= len(A) <= 50
1 <= len(B) <= 25
1 <= len(B[i]) <= 20
Examples:

Input 1:
    A = "b"
    B = ["aabbb"]

Output 1:
    []

Input 1:
    A = "catsanddog",
    B = ["cat", "cats", "and", "sand", "dog"]

Output 1:
    ["cat sand dog", "cats and dog"]
*/

vector<string> solve(string &A, int idx, set<string> &mp, set<pair<int, vector<string>>> &dp)
{
    vector<string> sentences;
    for(int i=idx; i<A.length(); i++)
    {
        string substring = A.substr(idx, i-idx+1);
        if(mp.find(substring)!=mp.end())
        {
            if(i==A.length()-1)
            {
                sentences.push_back(substring);
                return sentences;
            }
            vector<string> ret = solve(A, i+1, mp, dp);
            for(auto sentence: ret)
            {
                sentences.push_back(substring+" "+sentence);
            }
        }
    }
    return sentences;
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    
    set<string> mp;
    for(auto s: B)
    {
        mp.insert(s);
    }
    
    set<pair<int, vector<string>>> dp;

    return solve(A, 0, mp, dp);
}
