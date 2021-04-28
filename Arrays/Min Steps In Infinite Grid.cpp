
int dist(int x1, int y1, int x2, int y2) {
    if(x1==x2 || y1==y2) {
        if(x1==x2) {
            return abs(y2-y1);
        }
        else {
            return abs(x2-x1);
        }
    }
    int del = min(abs(x2-x1), abs(y2-y1));
    
    if(x2>x1) {
        if(y2>y1) {
            x1 += del;
            y1 += del;
        }
        else
        {
            x1 += del;
            y1 -= del;
        }
    }
    else {
        if(y2>y1) {
            x1 -= del;
            y1 += del;
        }
        else {
            x1 -= del;
            y1 -= del;
        }
    }
    
    if(x1==x2) {
        return (del + abs(y1-y2));
    }
    else {
        return (del + abs(x1-x2));
    }
}

int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    
    int ans = 0;
    
    for(int i=0; i<A.size()-1; i++) {
        ans += dist(A[i], B[i], A[i+1], B[i+1]);
    }
    
    return ans;
    
}
