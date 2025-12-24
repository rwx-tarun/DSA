Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 

Constraints:

1 <= s.length, p.length <= 3 * 104
s and p consist of lowercase English letters.

class Solution {
public:
    bool check(vector<int> & mp1 , vector<int> & mp2){
        for(int i=0;i<26;i++){
            if(mp1[i] != mp2[i])    return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>mp1(26,0),mp2(26,0);
        for(auto x:p){
            mp2[x-'a']++;
        }
        int i=0,j=0,n = s.length();
        int m = p.length();
        vector<int> res;
        while(j<n){
            mp1[s[j]-'a']++;
            int sz = j-i+1;
            cout<<"i "<<i<<endl;
            cout<<"j "<<j<<endl;
            if(sz == m){
                bool checkB = check(mp1,mp2);
                cout<<"check "<<checkB<<endl;
                if(checkB){
                    res.push_back(i);
                }
                mp1[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return res;
    }
};
