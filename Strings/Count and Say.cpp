string Solution::countAndSay(int A) {
    
    string prev="1";
    
    for(int i=2; i<=A; i++)
    {
        char curr_char=prev[0];
        int curr_cnt=1;
        
        string temp="";
        
        for(int i=1; i<prev.length(); i++)
        {
            if(prev[i]!=curr_char)
            {
                temp += to_string(curr_cnt)+curr_char;
                curr_char=prev[i];
                curr_cnt=1;
            }
            else
            {
                curr_cnt++;
            }
        }
        
        temp += to_string(curr_cnt)+curr_char;
        prev=temp;
    }
    
    return prev;
    
}
