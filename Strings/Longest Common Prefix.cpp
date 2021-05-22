string Solution::longestCommonPrefix(vector<string> &A) {
    
    if(A.size()==0)
    {
        return "";
    }
    
    string ans="";
    
    for(int i=1; i<=A[0].length(); i++)
    {
        string temp = A[0].substr(0, i);
        int flag=0;
        for(int j=1; j<A.size(); j++)
        {
            if(temp!=A[j].substr(0, i))
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            break;
        }
        ans=temp;
    }
    
    return ans;
    
}
