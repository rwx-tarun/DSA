1456. Maximum Number of Vowels in a Substring of Given Length


class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int j = 0,i=0;
        int mx = 0, vow = 0;
        while(j<n){
            if(isVowel(s[j])){
                vow++;
            }
           
            int sz = j-i+1;
            if(sz == k){
                mx = max(mx,vow);
                if(isVowel(s[i])){
                    vow--;
                }
                i++;
            }
            j++;
        }
        return mx;
    }
};
