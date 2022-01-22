
/*
Number following a pattern 

https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#

PS: Can also be done easily using stack. When you see D, push cnt to stack and cnt++. When you see I, push cnt, cnt++ 
and also pop out all elements from stack and print them. THis process goes on till last.
At last additionally push cnt, and pop out all elements from stack and print them.
*/





string printMinNumberForPattern(string s){
        int i = 0, j = 0;
        string res = "";
        string tm = "";
        int pIdx = -1;
        int cnt = 1;
        while(i < s.size())
        {
            if(s[i] == 'I')
            {
                int sz = i - pIdx;
                tm = "";
                for(int k = 1; k <= sz; k++)
                {
                    char ch = '0'+cnt;
                    cnt++;
                    tm.push_back(ch);
                }
                reverse(tm.begin(), tm.end());
                res = res + tm;
                pIdx = i;
            }
           i++;
        }
        int sz = s.size()-pIdx;
        tm = "";
        for(int k = 1; k <= sz; k++)
        {
            char ch = '0'+cnt;
            cnt++;
            tm.push_back(ch);
        }
        reverse(tm.begin(), tm.end());
        res = res + tm;
        
        return res;
        
    }


    //OR using Stack

    int main() {
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        stack<int>st;
        int cnt = 1;
        string res;
        for(int i = 0;i<s.length();i++)
        {
            char ch = s[i];
            if(ch == 'D')
            {
                st.push(cnt); cnt++;
            }
            else
            {
                st.push(cnt); cnt++;
                while(!st.empty())
                {
                    int x = st.top(); st.pop();
                    res = res + to_string(x);
                }
            }
        }
        st.push(cnt); 
        while(!st.empty())
        {
            int x = st.top(); st.pop();
            res = res + to_string(x);
        }
        cout << res << endl;
    }
    return 0;
}