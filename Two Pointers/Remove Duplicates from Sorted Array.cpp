int Solution::removeDuplicates(vector<int> &A) {
    
    
    if(A.size()==1)
    {
        return 1;
    }
    
    if(A[0]==A[A.size()-1])
    {
        A.resize(1);
        return 1;
    }
    
    int i=0;
    int j=1;
    
    while(j<A.size())
    {
        if(A[i]==A[j])
        {
            j++;
        }
        else
        {
            i++;
            A[i]=A[j];
            j++;
        }
    }
    
    A.resize(0, i);
    
    return i+1;
    
}
