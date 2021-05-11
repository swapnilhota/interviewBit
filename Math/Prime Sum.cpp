bool check(int x) {
    for(int i=2; i*i<=x; i++) {
        if(x%i==0) {
            return false;
        }
    }
    
    return true;
}

vector<int> Solution::primesum(int A) {
    
    vector<int> ans;
    
    for(int i=2; i<A; i++) {
        if(check(i)&&check(A-i)) {
            ans.push_back(i);
            ans.push_back(A-i);
            break;
        }
    }
    
    return ans;
    
}
