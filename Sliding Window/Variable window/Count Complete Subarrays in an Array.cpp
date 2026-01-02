


799. Count Complete Subarrays in an Array
You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

 

Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int i=0, j=0, n = nums.size();
        unordered_map<int,int>mp;
        int cnt =0;
        for(auto x:nums){
            if(mp.find(x) == mp.end()){ 
                cnt++;
            }
            mp[x]++;
        }
        mp.clear();
        int res = 0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size() == cnt){
                res = res + n-j;
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};
