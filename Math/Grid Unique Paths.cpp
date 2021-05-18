int Solution::uniquePaths(int A, int B) {
    
    if(A==1 || B==1)
    {
        return 1;
    }
    
    int arr[A][B];
    
    arr[A-1][B-1]=0;
    
    for(int i=0; i<A-1; i++)
    {
        arr[i][B-1]=1;
    }
    
    for(int j=0; j<B-1; j++)
    {
        arr[A-1][j]=1;
    }
    
    for(int i=A-2; i>=0; i--)
    {
        for(int j=B-2; j>=0; j--)
        {
            arr[i][j] = arr[i+1][j]+arr[i][j+1];
        }
    }
    
    return arr[0][0];
    
}
