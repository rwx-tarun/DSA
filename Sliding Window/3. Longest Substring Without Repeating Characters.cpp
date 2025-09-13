PATTERN 2 
//   - based on pattern 2 variable size window 
// 1. add the right element 
// 2. check the condition windows size 
// 3. calculate the result 



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right]]++;
            while (freq[s[right]] >= 2){
                freq[s[left]]--;
                if (freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
