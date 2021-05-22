void Solution::merge(vector<int> &A, vector<int> &B) {
    
    int n = A.size();
    int m = B.size();
    
    A.resize(n+m);
    
    int i=n-1;
    int j=m-1;
    
    while(i>=0 && j>=0)
    {
        if(A[i]<B[j])
        {
            A[i+j+1] = B[j];
            j--;
        }
        else
        {
            A[i+j+1] = A[i];
            i--;
        }
    }
    
    while(j>=0)
    {
        A[j]=B[j];
        j--;
    }
}
