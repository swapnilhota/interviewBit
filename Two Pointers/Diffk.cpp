int Solution::diffPossible(vector<int> &A, int B) {
    
    if(A.size()<2)
    {
        return 0;
    }
    
    if(A[A.size()-1]<B)
    {
        return 0;
    }
    
    for(int i=0; i<A.size()-1; i++)
    {
        for(int j=A.size()-1; j>i; j--)
        {
            if(A[j]-A[i]==B)
            {
                return 1;
            }
            if(A[j]-A[i]<B)
            {
                break;
            }
        }
    }
    
    return 0;
    
}
