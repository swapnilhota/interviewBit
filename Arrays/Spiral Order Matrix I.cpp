vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    
    int left=0;
    int top=0;
    int right=A[0].size()-1;
    int bottom = A.size()-1;
    
    char flag = 'r';
    
    vector<int> ans;
    
    while(left<=right && top<=bottom) {
        if(flag=='r') {
            for(int i=left; i<=right; i++) {
                ans.push_back(A[top][i]);
            }
            flag='d';
            top++;
            continue;
        }
        if(flag=='d') {
            for(int i=top; i<=bottom; i++) {
                ans.push_back(A[i][right]);
            }
            right--;
            flag='l';
            continue;
        }
        if(flag=='l') {
            for(int i=right; i>=left; i--) {
                ans.push_back(A[bottom][i]);
            }
            bottom--;
            flag='u';
            continue;
        }
        if(flag=='u') {
            for(int i=bottom; i>=top; i--) {
                ans.push_back(A[i][left]);
            }
            left++;
            flag='r';
            continue;
        }
    }
    
    return ans;
    
}
