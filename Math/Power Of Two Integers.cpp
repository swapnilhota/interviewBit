int Solution::isPower(int A) {
    
    if(A==1) {
        return 1;
    }
    
    for(int i=2; i*i<=A+1; i++) {
        if(A%i==0) {
            for(int j=2; j<=32; j++) {
                if((int)pow(i, j)==A) {
                    return 1;
                }
            }
        }
    }
    
    return 0;
    
}
