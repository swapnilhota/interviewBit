#define M 1000000007

int Solution::nchoc(int A, vector<int> &B) {
    
    long long ans = 0;
    
    priority_queue<long long> max_heap;
    
    for(auto i:B)
    {
        max_heap.push((long long)i);
    }
    
    while(A>0)
    {
        long long tmp = max_heap.top();
        max_heap.pop();
        ans += tmp;
        tmp = tmp/2;
        max_heap.push(tmp);
        A--;
    }
    
    return ans%M;
    
}
