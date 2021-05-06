vector<int> Solution::solve(vector<int> &A) {
    vector<int> neg;
    vector<int> pos;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]<0)
        {
            neg.push_back(A[i]);
        }
        else
        {
            pos.push_back(A[i]);
        }
    }
        
        for(int i=0; i<neg.size();i++)
        {
            neg[i] = neg[i]*neg[i];
        }
        
        for(int i=0; i<pos.size();i++)
        {
            pos[i] = pos[i]*pos[i];
        }
        
        vector<int> ans;
        
        int i=neg.size()-1;
        int j=0;
        
        while(i>=0 && j<pos.size())
        {
            if(neg[i]>pos[j])
            {
                ans.push_back(pos[j]);
                j++;
            }
            else
            {
                ans.push_back(neg[i]);
                i--;
            }
        }
        
        while(i>=0)
        {
            ans.push_back(neg[i]);
            i--;
        }
        
        while(j<pos.size())
        {
            ans.push_back(pos[j]);
            j++;
        }
        
        return ans;
}
