int Solution::solve(int A, vector<int> &B) {
    
    long long total_sum = 0;
    
    for(int i=0; i<A; i++)
    {
        total_sum += B[i];
    }
    
    if(total_sum % 3 != 0)
    {
        return 0;
    }
    
    long long part_sum = total_sum/3;
    
    int ans = 0;
    
    long long temp1 = 0;
    
    for(int i=0; i<A-2; i++)
    {
        temp1 += B[i];
        if(temp1==part_sum)
        {
            long long temp2 = 0;
            for(int j=i+1; j<A-1; j++)
            {
                temp2 += B[j];
                if(temp2==part_sum)
                {
                    ans++;
                }
            }
        }
    }
    
    return ans;
    
}
