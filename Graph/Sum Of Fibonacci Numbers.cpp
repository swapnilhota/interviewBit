/*
How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?
Note : repetition of number is allowed.

Example:

N = 4
Fibonacci numbers : 1 1 2 3 5 .... so on
here 2 + 2 = 4 
so minimum numbers will be 2 
*/

int Solution::fibsum(int A) {
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);

    int i=2;
    while(1)
    {
        int x = fib[i-1]+fib[i-2];
        if(x>A)
        {
            break;
        }
        fib.push_back(x);
        i++;
    }

    i = fib.size()-1;
    int ans=0;
    
    while(A>0)
    {
        if(fib[i]<=A)
        {
            A -= fib[i];
            ans++;
        }
        else
        {
            i--;
        }
    }
    
    return ans;
}
