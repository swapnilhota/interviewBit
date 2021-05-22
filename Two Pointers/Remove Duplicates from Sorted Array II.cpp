int Solution::removeDuplicates(vector<int> &A) {
    
    if(A.size()==1)
    {
        return 1;
    }
    if(A[0]==A[A.size()-1])
    {
        A.resize(0, 1);
        return 2;
    }
    
    int i=0;
    int j=1;
    
    int cnt=1;
    
    while(j<A.size())
    {
        if(A[i]==A[j])
        {
            if(cnt>=2)
            {
                j++;
            }
            else
            {
                i++;
                A[i]=A[j];
                j++;
                cnt++;
            }
        }
        else
        {
            i++;
            A[i]=A[j];
            j++;
            cnt=1;
        }
    }
    
    A.resize(0, i);
    
    return i+1;
    
}
