int Solution::strStr(const string A, const string B) {
    
    int ans=-1;
    
    for(int i=0; i<A.length(); i++)
    {
        if(A[i]==B[0])
        {
            if(A.length()-i < B.length())
            {
                continue;
            }
            int j=i+1;
            int x=1;
            int flag=0;
            while(x<B.length())
            {
                if(A[j]!=B[x])
                {
                    flag=1;
                    break;
                }
                x++;
                j++;
            }
            if(flag==0)
            {
                return i;
            }
        }
    }
    
    return ans;
    
}
