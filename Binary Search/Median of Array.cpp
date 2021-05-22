double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    
    int n = A.size();
    int m = B.size();
    
    if(n==0 || m==0)
    {
        if(n==0 && m==0)
        {
            return 0;
        }
        else if(n==0)
        {
            if(m%2==0)
            {
                return (double)(B[m/2]+B[m/2-1])/2;
            }
            else
            {
                return (double)B[m/2];
            }
        }
        else
        {
            if(n%2==0)
            {
                return (double)(A[n/2]+A[n/2-1])/2;
            }
            else
            {
                return (double)A[n/2];
            }
        }
    }
    
    if(n<m)
    {
        return findMedianSortedArrays(B, A);
    }
    
    int low=0;
    int high=m;
    
    while(low<=high)
    {
        int i = (high-low)/2 + low;
        int j = (n+m)/2-i;
        
        if(i==0)
        {
            int x = A[j-1];
            int y = min(B[0], A[j]);
            if(x>y)
            {
                low=i+1;
                continue;
            }
            double ans;
            if((n+m)%2==0)
            {
                ans = (double)(x+y)/2;
            }
            else
            {
                ans = y;
            }
            return ans;
        }
        else if(i==m)
        {
            if(m == (n+m)/2)
            {
                if((n+m)%2==0)
                {
                    return (double)(B[i-1]+A[0])/2;
                }
                else
                {
                    return (double)A[0];
                }
            }
            else
            {
                if((n+m)%2==0)
                {
                    int x1 = A[j-1];
                    int x2 = B[i-1];
                    int y = A[j];
                    
                    return (double)(max(x1, x2)+y)/2;
                }
                else
                {
                    return (double)A[j];
                }
            }
        }
        else
        {
            int x1, x2, y1, y2;
            x1 = A[j-1];
            x2 = B[i-1];
            y1 = A[j];
            y2 = B[i];
            
            if(x1>y2 || y1<x2)
            {
                if(x1>y2)
                {
                    low=i+1;
                }
                else if(y1<x2)
                {
                    high=i-1;
                }
            }
            else
            {
                if((n+m)%2==0)
                {
                    double ans = (double)(max(x1, x2)+min(y1, y2))/2;
                    return ans;
                }
                
                return min(y1, y2);
            }
            
        }
         
    }
    
}
