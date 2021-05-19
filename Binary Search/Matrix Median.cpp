int Solution::findMedian(vector<vector<int> > &A) {
    
    int n=A.size();
    int m=A[0].size();
    
    int minTerm = INT_MAX;
    int maxTerm = INT_MIN;
    
    for(int i=0; i<n; i++)
    {
        minTerm = min(minTerm, A[i][0]);
        maxTerm = max(maxTerm, A[i][m-1]);
    }
    
    int req_place = (n*m+1)/2;
    
    while(minTerm<maxTerm)
    {
        int mid = (maxTerm+minTerm)/2;
        int place=0;
        
        for(int i=0; i<n; i++)
        {
            place += (upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin());
            // upper_bound returns an interator to the first big element it faces after mid
        }
        
        if(place<req_place)
        {
            minTerm = mid+1;
        }
        else
        {
            maxTerm = mid;
        }
    }
    
    return minTerm;
    
}
