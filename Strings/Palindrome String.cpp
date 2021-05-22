int Solution::isPalindrome(string A) {
    
    string temp = "";
    
    for(char i : A)
    {
        i = tolower(i);
        if(i>='a' && i<='z' || i>='0' && i<='9')
        {
            temp += i;
        }
    }
    
    string temp2 = temp;
    reverse(temp2.begin(), temp2.end());
    if(temp2==temp)
    {
        return 1;
    }
    
    return 0;
    
}
