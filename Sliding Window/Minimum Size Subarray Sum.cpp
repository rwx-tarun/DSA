
Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint





class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int n = nums.size();
        int start = 0, end = 0;
        long long sum = 0;
        int minLen = INT_MAX;

        while (end < n) {
            sum += nums[end];
            while (start <= end && sum >= target) {
                minLen = min(minLen, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return (minLen == INT_MAX ? 0 : minLen);
    }
};
