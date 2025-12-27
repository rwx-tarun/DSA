1234. Replace the Substring for Balanced String
You are given a string s of length n containing only four kinds of characters: 'Q', 'W', 'E', and 'R'.

A string is said to be balanced if each of its characters appears n / 4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of the same length to make s balanced. If s is already balanced, return 0.

 

Example 1:

Input: s = "QWER"
Output: 0
Explanation: s is already balanced.



class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        for (char c : s) 
            freq[c]++;
        
        int required = n / 4;

        if (freq['Q'] == required && freq['W'] == required &&
            freq['E'] == required && freq['R'] == required)
            return 0;
        
        int res = n;
        int start = 0, end = 0;
        

        while (end < n) {
            // Expand window by including s[right]
            freq[s[end]]--;
            
            // Shrink while the remaining string is balanced
            while (freq['Q'] <= required &&
                   freq['W'] <= required &&
                   freq['E'] <= required &&
                   freq['R'] <= required) {
                
                res = min(res, end - start + 1);
                freq[s[start]]++;
                start++;
            }
            
            end++;
        }
        
        return res;
    }
};
