void helper(string A, map<char, string> m, set<string> &ans, string tmp, int idx)
{
    if(idx==A.length())
    {
        ans.insert(tmp);
        return;
    }
    
    for(char c: m[A[idx]])
    {
        helper(A, m, ans, tmp+c, idx+1);
    }
}

vector<string> Solution::letterCombinations(string A) {
    
    map<char, string> m;
    m['0']="0";
    m['1']="1";
    m['2']="abc";
    m['3']="def";
    m['4']="ghi";
    m['5']="jkl";
    m['6']="mno";
    m['7']="pqrs";
    m['8']="tuv";
    m['9']="wxyz";
    
    set<string> ans;
    string tmp="";
    
    helper(A, m, ans, tmp, 0);
    
    vector<string> res;
    
    for(auto i:ans)
    {
        res.push_back(i);
    }
    
    return res;
    
}
