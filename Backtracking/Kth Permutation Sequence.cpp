long long fact(int n)
{
    if(n==0 || n==1)
    {
        return 1LL;
    }
    return n*fact(n-1);
}

void helper(int A, int B, bool* visited, string &ans, int rem)
{
    if(rem==0)
    {
        return;
    }
    
    for(int i=1; i<=A; i++)
    {
        if(visited[i]==false)
        {
            if(rem>15)
            {
                ans += to_string(i);
                visited[i]=true;
                helper(A, B, visited, ans, rem-1);
            }
            else if(fact(rem-1)>=B)
            {
                ans += to_string(i);
                visited[i]=true;
                helper(A, B, visited, ans, rem-1);
            }
            else
            {
                B -= fact(rem-1);
                continue;
            }
        }
    }
}

string Solution::getPermutation(int A, int B) {
    
    string ans="";
    
    bool* visited= new bool[A+1]();
    
    helper(A, B, visited, ans, A);
    
    return ans;
    
}
