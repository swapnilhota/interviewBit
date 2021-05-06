bool compare(string a, string b)
{
    string temp1 = a+b;
    string temp2 = b+a;
    
    if(temp1>temp2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Solution::largestNumber(const vector<int> &A) {
    string a[A.size()];
    for(int i=0; i<A.size(); i++)
    {
        a[i] = to_string(A[i]);
    }
    sort(a, a+A.size(), compare);
    
    string ans = "";
    
    for(int i=0; i<A.size(); i++)
    {
        ans += a[i];
    }
    
    int leading_zeroes=0;
    
    for(int i=0; i<ans.length(); i++)
    {
        if(ans[i]=='0')
        {
            leading_zeroes++;
        }
        else
        {
            break;
        }
    }
    
    if(leading_zeroes == ans.length())
    {
        ans = "0";
    }
    
    return ans;
}
