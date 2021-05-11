//solved using Power Matrix Method 

#define m 1000000007

void multiply(long long F[2][2], long long M[2][2]) {
    long long a = (((F[0][0]%m)*(M[0][0]%m))%m + ((F[0][1]%m)*(M[1][0]%m))%m)%m;
    long long b = (((F[0][0]%m)*(M[0][1]%m))%m + ((F[0][1]%m)*(M[1][1]%m))%m)%m;
    long long c = (((F[1][0]%m)*(M[0][0]%m))%m + ((F[1][1]%m)*(M[1][0]%m))%m)%m;
    long long d = (((F[1][0]%m)*(M[0][1]%m))%m + ((F[1][1]%m)*(M[1][1]%m))%m)%m;
    
    F[0][0] = a%m;
    F[0][1] = b%m;
    F[1][0] = c%m;
    F[1][1] = d%m;
}

void power(long long F[2][2], int n) {
    if(n == 0 || n == 1) {
       return; 
    }
       
    long long M[2][2] = {{1, 1}, {1, 0}};
     
    power(F, n / 2);
    multiply(F, F);
     
    if (n % 2 != 0) {
        multiply(F, M);
    }
}

int Solution::solve(int A) {
    
    if(A==1 || A==2) {
        return 1;
    }
    
    long long F[2][2] = {{1, 1}, {1, 0}};
    
    power(F, A-1);
    
    return F[0][0]%m;
    
}
