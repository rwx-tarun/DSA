Fruit Into Baskets.cpp
 - problem is max length window with max k distinct elements 
Same Pattern 2 problems 

TC - O(2n)
SC  - O(1)

class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        unordered_map<char,int> freq;
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            freq[fruits[right]]++;
            while (freq.size() > 2){
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) freq.erase(fruits[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
