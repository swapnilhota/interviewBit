/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/

void helper(string s, int n, vector<string> &v, int left)
{
    if(left==0)
    {
        v.push_back(s);
        return;
    }
    if(n==0)
    {
        return;
    }

    helper(s, n-1, v, left);
    string t = s.substr(0, n)+'.'+s.substr(n);
    helper(t, n-1, v, left-1);
}

bool check(string &s)
{
    string temp = "";
    for(auto c: s)
    {
        if(c=='.')
        {
            if(temp=="")
            {
                return false;
            }
            string num = to_string(stoi(temp));
            if(stoi(temp)>255)
            {
                return false;
            }
            if(temp.length()>3)
            {
                return false;
            }
            if(num.length()!=temp.length())
            {
                return false;
            }
            temp="";
        }
        else
        {
            temp += c;
        }
    }

    if(temp=="")
    {
        return false;
    }
    if(stoi(temp)>255)
    {
        return false;
    }
    if(temp.length()>3)
    {
        return false;
    }
    string num = to_string(stoi(temp));
    if(num.length()!=temp.length())
    {
        return false;
    }

    return true;
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string> v;
    helper(A, A.length(), v, 3);
    vector<string> res;
    for(auto &s: v)
    {
        if(check(s))
        {
            res.push_back(s);
        }
    }
    return res;
}
