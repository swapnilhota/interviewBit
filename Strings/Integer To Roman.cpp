string Solution::intToRoman(int A) {
    
    if(A==0)
    {
        return "";
    }
    
    string ans="";
    
    if(A>=1000)
    {
        ans += "M";
        return ans += intToRoman(A-1000);
    }
    if(A>=500)
    {
        if(A>=900)
        {
            ans += "CM";
            return ans += intToRoman(A-900);
        }
        else
        {
            ans += "D";
            return ans += intToRoman(A-500);
        }
    }
    if(A>=100)
    {
        if(A>=400)
        {
            ans += "CD";
            return ans += intToRoman(A-400);
        }
        else
        {
            ans += "C";
            return ans += intToRoman(A-100);
        }
    }
    if(A>=50)
    {
        if(A>=90)
        {
            ans += "XC";
            return ans += intToRoman(A-90);
        }
        else
        {
            ans += "L";
            return ans += intToRoman(A-50);
        }
    }
    if(A>=10)
    {
        if(A>=40)
        {
            ans += "XL";
            return ans += intToRoman(A-40);
        }
        else
        {
            ans += "X";
            return ans += intToRoman(A-10);
        }
    }
    if(A>=5)
    {
        if(A>=9)
        {
            ans += "IX";
            return ans += intToRoman(A-9);
        }
        else
        {
            ans += "V";
            return ans += intToRoman(A-5);
        }
    }
    if(A>0)
    {
        if(A>=4)
        {
            ans += "IV";
            return ans += intToRoman(A-4);
        }
        else
        {
            ans += "I";
            return ans += intToRoman(A-1);
        }
    }
    
}
