int Solution::sqrt(int A) {
    
    double left = 0;
    double right = A;
    
    while(left<right)
    {
        double mid = (right-left)/2 + left;
        
        if(floor(A/mid) == floor(mid))
        {
            return mid;
        }
        
        if(mid*mid < A)
        {
            left=mid;
        }
        else
        {
            right=mid;
        }
    }
    
    return floor(left);
    
}
