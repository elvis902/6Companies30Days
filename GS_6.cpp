 
/*

1071. Greatest Common Divisor of Strings

https://leetcode.com/problems/greatest-common-divisor-of-strings/

THere are also some other 3 or 4 lines easy solution using some observation and GCD

*/





 string gcdOfStrings(string str1, string str2) {
        string small = "", large = "";
        if(str1.size() < str2.size()) {small = str1; large = str2;}
        else {small = str2; large = str1;}
        
        string res = "";
        for(int i = small.size(); i >= 1 ; i--)
        {
            string pre = small.substr(0, i);
            if(small.size() % pre.size() != 0 || large.size() % pre.size() != 0)
                continue;
            int sz = pre.size();
            bool flag1 = true, flag2 = true;
            for(int i = 0; i < small.size(); i++)
            {
                if(small[i] != pre[i%sz])
                {
                    flag1 = false; break;
                }
            }
            if(flag1 == false) continue;
            for(int i = 0; i < large.size(); i++)
            {
                if(large[i] != pre[i%sz])
                {
                    flag2 = false; break;
                }
            }
            if(flag2 == true)
            {
                res = pre;
                break;
            }
        }
        return res;
    }