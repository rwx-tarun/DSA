1358. Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 



class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0 , j = 0 , n = s.length();
        int res = 0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]-'a']++;
            while(mp.size() == 3){
                res = res + n-j;
                mp[s[i] - 'a']--;
                if(mp[s[i] - 'a'] == 0){
                    mp.erase(s[i] - 'a');
                }
                i++;
            }
            j++;
        }
        return res;
    }
};
