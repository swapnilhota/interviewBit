int Solution::isPalindrome(int A) {
    if(A<0)
    {
        return 0;
    }
    string a = to_string(A);
    string b = a;
    reverse(b.begin(), b.end());
    if(a==b)
    {
        return 1;
    }
    return 0;
}
