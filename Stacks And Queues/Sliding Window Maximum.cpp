vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    
    deque <int> dq;
        vector <int> ans;
        
        for (int i = 0; i < B; i++){
            
            while (!dq.empty() && A[dq.back()] <= A[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        ans.push_back(A[dq.front()]);
        
        for (int i = B; i < A.size(); i++){
            int last_pos = i-B+1;
            while (!dq.empty() && dq.front() < last_pos){
                dq.pop_front();
            }
            
            while (!dq.empty() && A[dq.back()] <= A[i]){
                dq.pop_back();
            }
            
            dq.push_back(i);
            ans.push_back(A[dq.front()]);
        }
        
        return ans;
    
}
