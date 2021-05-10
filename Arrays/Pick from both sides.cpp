int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    int sum=0;
    for(int i=0; i<B; i++) {
        sum += A[i];
    }
    int i = B-1;
    int j = n-1;
    int temp = sum;
    while(i>=0) {
        temp -= A[i];
        temp += A[j];
        i--;
        j--;
        sum = max(sum, temp);
    }
    return sum;
}
