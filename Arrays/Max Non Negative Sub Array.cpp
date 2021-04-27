vector<int> Solution::maxset(vector<int> &A) {
    
    vector<int> ans;
    
    long long sum=0;
    long long maxSum=INT_MIN;
    
    map<long long, vector<int>> mp;
    
    vector<int> temp;
    
    for(int i=0; i<A.size(); i++) {
        
        if(A[i]<0) {
            if(temp.size()>0) {
                if(sum>maxSum) {
                maxSum=sum;
                ans=temp;
                }
                else if(sum==maxSum) {
                    if(temp.size()>ans.size()) {
                        ans=temp;
                    }
                }
                    
            }
            sum=0;
            temp.clear();
            continue;
        }
        sum += A[i];
        temp.push_back(A[i]);
    }
    
    if(sum>maxSum) {
                maxSum=sum;
                ans=temp;
                }
                else if(sum==maxSum) {
                    if(temp.size()>ans.size()) {
                        ans=temp;
                    }
                }
    
    return ans;
    
}
