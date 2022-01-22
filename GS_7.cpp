 		
/*
Total Decoding Messages

https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#

Dp, Medium

*/






 		int M = 1e9 + 7;
	    int solve(string s, int idx, vector<int>&dp)
	    {
	        if(idx == s.size()) return 1;
	        
	        if(dp[idx] != -1) return dp[idx];
	        
	        int tcnt = 0;
	        char ch1 = s[idx];
	        if(ch1 == '0') return tcnt;
	        int x1 = ch1 - '0';
	        tcnt = (tcnt + solve(s, idx+1, dp))%M;
	        
	        if(s.size()-idx >= 2)
	        {
	            string s2 = s.substr(idx, 2);
	            int x2 = stoi(s2);
	            if(x2 >= 1 && x2 <= 26)
	               tcnt = (tcnt + solve(s, idx+2, dp))%M;
	        }
	        return dp[idx] = tcnt%M;
	    }
		int CountWays(string str){
		    int sz = str.size();
		    vector<int>dp(sz, -1);
		    int res = solve(str, 0, dp);
		    return res;
		}