int Solution::colorful(int A) {
    
    string s = to_string(A);
    
    int n=s.length();
    
    vector<string> v;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=n-i; j++)
        {
            v.push_back(s.substr(j, i));
        }
    }
    
    set<int> st;
    
    for(string str:v)
    {
        int x=1;
        for(char c:str)
        {
            x = x*(c-'0');
        }
        st.insert(x);
    }
    
    if(st.size()==v.size())
    {
        return 1;
    }
    
    return 0;
    
}
