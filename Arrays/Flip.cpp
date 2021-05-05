vector<int> Solution::flip(string A) {
    
    int idx1;
    int idx2;
    
    int max1s = 0;
    
    int zeroes = 0;
    
    for(int i=0; i<A.length(); i++)
    {
        if(A[i]=='0')
        {
            zeroes++;
        }
    }
    
    if(zeroes==0)
    {
        vector<int> v;
        return v;
    }
    
    
    int temp=0;
    int tempL;
    int tempR;
    
    int flag=0;
    
    for(int l=0; l<A.length(); l++)
    {
        if(A[l]=='0')
        {
            temp++;
            if(flag==0)
            {
                tempL=l+1;
                flag=1;
            }
        }
        else
        {
            temp--;
        }
        if(temp>max1s)
        {
            max1s = temp;
            idx1 = tempL;
            idx2 = l+1;
        }
        if(temp<0)
        {
            flag=0;
            temp=0;
        }
    }
    
    vector<int> v;
    v.push_back(idx1);
    v.push_back(idx2);
    
    return v;
    
}
