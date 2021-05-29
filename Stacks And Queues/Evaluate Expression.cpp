int Solution::evalRPN(vector<string> &A) {
    
    stack<string> s;
    
    int ans=0;
    
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]=="+")
        {
            int a = stoi(s.top());
            s.pop();
            int b = stoi(s.top());
            s.pop();
            
            int c = a+b;
            s.push(to_string(c));
        }
        else if(A[i]=="-")
        {
            int a = stoi(s.top());
            s.pop();
            int b = stoi(s.top());
            s.pop();
            
            int c = b-a;
            s.push(to_string(c));
            
            
        }
        else if(A[i]=="*")
        {
            int a = stoi(s.top());
            s.pop();
            int b = stoi(s.top());
            s.pop();
            
            int c = a*b;
            s.push(to_string(c));
           
        }
        else if(A[i]=="/")
        {
            int a = stoi(s.top());
            s.pop();
            int b = stoi(s.top());
            s.pop();
            
            int c = b/a;
            s.push(to_string(c));
            
            
        }
        else
        {
            s.push(A[i]);
        }
    }
    
    return stoi(s.top());
    
}
