/*
Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of A = “great”:


    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
 
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that “rgeat” is a scrambled string of “great”.

Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that “rgtae” is a scrambled string of “great”.



Given two strings A and B of the same length, determine if B is a scrambled string of S.



Input Format:

The first argument of input contains a string A.
The second argument of input contains a string B.
Output Format:

Return an integer, 0 or 1:
    => 0 : False
    => 1 : True
Constraints:

1 <= len(A), len(B) <= 50
Examples:

Input 1:
    A = "we"
    B = "we"

Output 1:
    1

Input 2:
    A = "phqtrnilf"
    B = "ilthnqrpf"
    
Output 2:
    0
*/

bool check(string a, string b, unordered_map<string, int> &mp)
{
    if(a==b)
    {
        return true;
    }

    string curr = a+' '+b;
    if(mp[curr]!=0)
    {
        if(mp[curr]==1)
        {
            return true;
        }

        return false;
    }

    bool ans = false;

    for(int i=1; i<a.length(); i++)
    {
        //swap done
        auto a1 = check(a.substr(0, i), b.substr(b.length()-i), mp)&&check(a.substr(i), b.substr(0, b.length()-i), mp);
        //swap not done
        auto a2 = check(a.substr(0, i), b.substr(0, i), mp)&&check(a.substr(i), b.substr(i), mp);

        ans = ans || a1 || a2;

        if(ans)
        {
            mp[curr] = 1;
            return true;
        }
    }

    mp[curr] = -1;

    return ans;
}

int Solution::isScramble(const string A, const string B) {

    unordered_map<string, int> mp;
    return check(A, B, mp);
}
