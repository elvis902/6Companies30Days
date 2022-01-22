/*Given an array of strings, 
return all groups of strings that 
are anagrams.

https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/
*/


class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& v) {
        vector<vector<string>>res;
        unordered_map<string, vector<string>>m;
        for(auto it : v)
        {
            string str = it;
            sort(str.begin(), str.end());
            m[str].push_back(it);
        }
        for(auto it = m.begin(); it != m.end(); ++it)
        {
            res.push_back(it->second);
        }
        return res;
    }
};