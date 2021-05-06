vector<int> Solution::getRow(int A) {
    if(A==0)
    {
        vector<int> v;
        v.push_back(1);
        return v;
    }
    if(A==1)
    {
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        return v;
    }
    vector<int> v1;
    vector<int> v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(1);
    
    if(A==2)
    {
        return v1;
    }
    
    for(int i=3; i<=A; i++)
    {
        v2.clear();
        v2.push_back(1);
        for(int j=1; j<v1.size(); j++)
        {
            v2.push_back(v1[j]+v1[j-1]);
        }
        v2.push_back(1);
        v1 = v2;
    }
    
    return v1;
}
