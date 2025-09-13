1004. Max Consecutive Ones III

- instead of finding max flips 0 
- find length max zeros in window is k 

- Pattern 2 
  - increase count 1 if nums[right] == 0



class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, maxLen = 0;
        int cnt = 0;

        for (int right = 0; right < nums.size(); right++) {
            if(nums[right] == 0)
                cnt++;
            while (cnt > k){
                if(nums[left] == 0){
                    cnt--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
        
    }
};
