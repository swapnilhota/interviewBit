int convert(string s)
{
    int num = 0;
 
    // convert binary string into integer
    for (int i = 0; i < s.size(); i++) {
        num = num * 2 + (s[i] - '0');
    }
    return num;
}

int Solution::solve(int A) {
    
    if(A==1)
    {
        return 1;
    }
    if(A==2)
    {
        return 3;
    }
    int n = A;
    queue<string> q;
    q.push("11");
    n--;
    
    while(!q.empty())
    {
        string curr = q.front();
        q.pop();
        n--;
        
        if(n==0)
        {
            return convert(curr);
        }
        
        int mid = curr.length()/2;
        
        if(curr.length()%2==0)
        {
            string s0 = curr;
            string s1 = curr;
            
            s0.insert(mid, "0");
            s1.insert(mid, "1");
            
            q.push(s0);
            q.push(s1);
        }
        else
        {
            string ch(1, curr[mid]);
            string temp=curr;
            temp.insert(mid, ch);
            q.push(temp);
        }
    }
    
    return 0;
    
}
