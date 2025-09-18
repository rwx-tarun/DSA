Same as binary subarray sum problem 
- mark the odd numbers as 0 & even as 1 
call f(nums,k) - f(nums ,k-1)  = exactly for k 

TC - O(2*n)
SC = const 
class Solution {
public:
    int f(vector<int> & nums,int k){
        int left = 0;
        int n = nums.size(),cnt=0,res=0;
        for(int right =0;right<n;right++){
            cnt = cnt + nums[right]%2;
            while(cnt > k){
                cnt = cnt -  nums[left] % 2;  
                left++;
            }
            res = res + right-left+1;
        }
        return res;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
         return f(nums,k) - f(nums,k-1);
        
    }
};
