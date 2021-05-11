int Solution::solve(vector<string> &A) {
    if(A.size()<3) {
        return 0;
    }
    vector<double> v;
    int n = A.size();
    for(int i=0; i<n; i++) {
        v.push_back(stod(A[i]));
    }
    
    sort(v.begin(), v.end());
    
    int i=0;
    int j=n-1;
    
    while(i<j-1) {
        double a = v[i];
        double c = v[j];
        int mid = (i+j)/2;
        double b = v[mid];
        if(a+b+c>2) {
            j--;
        }
        else if(a+b+c<1) {
            i++;
        }
        else {
            return 1;
        }
    }
    
    return 0;
    
}
