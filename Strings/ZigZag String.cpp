string Solution::convert(string A, int B) {
    
    if(A=="")
    {
        return A;
    }
    
    if(B==1)
    {
        return A;
    }
    
    vector<vector<char>> v(B);
    
    int i=0;
    int flag=0;
    
    for(int j=0; j<A.length(); j++)
    {
        v[i].push_back(A[j]);
        if(i==B-1)
        {
            flag=1;
            i--;
        }
        else if(i==0)
        {
            flag=0;
            i++;
        }
        else if(flag==1)
        {
            i--;
        }
        else if(flag==0)
        {
            i++;
        }
    }
    
    string ans="";
    
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            ans += v[i][j];
        }
    }
    
    return ans;
    
}
