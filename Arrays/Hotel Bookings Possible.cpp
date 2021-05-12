struct Slot {
    int t;
    int val;
};

bool compare(Slot x, Slot y) {
    return x.t < y.t;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    if(K==0) {
        return 0;
    }
    
    int n = arrive.size();
    
    if(n==0) {
        return 1;
    }
    
    vector<Slot> v;
    
    for(int i=0; i<n; i++) {
        Slot temp;
        temp.t = arrive[i];
        temp.val = 1;
        v.push_back(temp);
        temp.t = depart[i];
        temp.val=-1;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end(), compare);
    
    int guests = 0;
    
    for(int i=0; i<v.size(); i++) {
        guests += v[i].val;
        if(i==v.size()-1) {
            if(guests>K){
                return 0;
            }
        } else {
            if(v[i].t==v[i+1].t) {
                continue;
            } 
            if(guests>K) {
                return 0;
            }
        }
    }
    
    return 1;
    
}
