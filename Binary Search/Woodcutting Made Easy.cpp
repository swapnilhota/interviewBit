int Solution::solve(vector<int> &A, int B) {
    
    sort(A.begin(), A.end());
    
    int woods=0;
    
    int n = A.size();
    
    int height=A[n-1];
    
    for(int i=n-1; i>=0; i--)
    {
        if(woods>=B)
        {
            return height;
        }
        
        if(i==0)
        {
            while(woods<B)
            {
                woods += (n-i);
                height--;
            }
            return height;
        }
        
        int temp = woods + (A[i]-A[i-1])*(n-i);
        
        if(temp>=B)
        {
            while(woods<B)
            {
                woods += (n-i);
                height--;
            }
            return height;
        }
        else
        {
            woods += (A[i]-A[i-1])*(n-i);
            height -= (A[i]-A[i-1]);
        }
    }
    
    return height;
    
}
