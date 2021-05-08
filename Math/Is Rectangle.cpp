int Solution::solve(int A, int B, int C, int D) {
    set<int> s;
    
    map<int, int> m;
    m[A]++;
    m[B]++;
    m[C]++;
    m[D]++;
    
    if(m[A]==4)
    {
        return 1;
    }
    
    for(auto i = m.begin(); i!=m.end(); i++)
    {
        if(i->second != 2)
        {
            return 0;
        }
    }
    
    return 1;
}
