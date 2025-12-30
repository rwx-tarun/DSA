2962. Count Subarrays Where Max Element Appears at Least K Times
You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
Example 2:

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int maxVal = *max_element(nums.begin(), nums.end());

        int start = 0, end = 0;
        int maxCnt = 0;
        long long res = 0;

        while(end < n){
            if(nums[end] == maxVal){
                maxCnt++;
            }
            while(maxCnt >= k){
                res += (n-end);
                if(nums[start] == maxVal){
                    maxCnt--;
                }
                start++;
            }
            end++;
        }
        return res;
    }
};
