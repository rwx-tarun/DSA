76. Minimum Window Substring


1. Pattern 2 problem 
-  add right element to map 
- check if windows is valid calculate result 
- shrink window 


Optimise - use array size 26 




class Solution {
public:
    bool check(unordered_map<char,int>& mp1, unordered_map<char,int>& mp2) {
        for (auto& [ch, freq] : mp2) {
            if (mp1[ch] < freq) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char,int> mp1, mp2;
        for (auto x : t) mp2[x]++;

        int left = 0, n = s.length();
        int res = INT_MAX;
        pair<int,int> val = {-1, -1};

        for (int right = 0; right < n; right++) {
            mp1[s[right]]++;

            while (check(mp1, mp2)) {
                if (res > (right - left + 1)) {
                    res = right - left + 1;
                    val = {left, right};
                }
                mp1[s[left]]--;
                if (mp1[s[left]] == 0) mp1.erase(s[left]);
                left++;
            }
        }

        if (val.first == -1) return ""; 
        return s.substr(val.first, val.second - val.first + 1);
    }

};
