/* Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.

https://practice.geeksforgeeks.org/problems/run-length-encoding/1/

*/



string encode(string s)
{     
   char ch = s[0];
   int cnt = 1;
   string res = "";
   for(int i = 1; i < s.size(); i++)
   {
       if(s[i] == s[i-1])
       {
           cnt++;
       }
       else
       {
           string d = to_string(cnt);
           res = res + ch + d;
           ch = s[i];
           cnt = 1;
       }
   }
   string d = to_string(cnt);
   res = res + ch + d;
   return res;
}     