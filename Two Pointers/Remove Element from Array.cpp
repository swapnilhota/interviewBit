int Solution::removeElement(vector<int> &A, int B) {
    
    int i=0;
    int j=0;
    
    while(j<A.size())
    {
        if(A[j]==B)
        {
            j++;
        }
        else
        {
            swap(A[i], A[j]);
            i++;
            j++;
        }
    }
    
    return i;
    
}
