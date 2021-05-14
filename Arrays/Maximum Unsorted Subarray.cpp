vector<int> Solution::subUnsort(vector<int> &A) {
    
    vector<int> temp = A;
    
    sort(temp.begin(), temp.end());
    
    int l=-1;
    int r=-1;
    
    for(int i=0; i<A.size(); i++) {
        if(temp[i]!=A[i]) {
            if(l==-1) {
                l=i;
            }
            else {
                r=i;
            }
        }
    }
    
    if(l==-1) {
        vector<int> v;
        v.push_back(-1);
        return v;
    }
    
    vector<int> ans;
    ans.push_back(l);
    ans.push_back(r);
    
    return ans;
    
}
