vector<int> Solution::findPerm(const string A, int B) {
    int min=0;
    int max=0;
    vector<int> ans;
    ans.push_back(0);
    for(int i=0; i<A.length(); i++) {
        if(A[i]=='I') {
            ans.push_back(max+1);
            max++;
        }
        else {
            ans.push_back(min-1);
            min--;
        }
    }
    int inc = 1+abs(min);
    for(int i=0; i<ans.size(); i++) {
        ans[i] += inc;
    }
    return ans;
}
