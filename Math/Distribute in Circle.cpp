int Solution::solve(int A, int B, int C) {
    int curr_pos = C;
    int circle_size = B;
    int items = A;
    
    while(1)
    {
        items--;
        if(items<=0)
        {
            break;
        }
        curr_pos = (curr_pos+1)%circle_size;
    }
    return curr_pos;
}
