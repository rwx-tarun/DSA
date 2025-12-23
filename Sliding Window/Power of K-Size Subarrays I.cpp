3254. Find the Power of K-Size Subarrays I
You are given an array of integers nums of length n and a positive integer k.

The power of an array is defined as:

Its maximum element if all of its elements are consecutive and sorted in ascending order.
-1 otherwise.
You need to find the power of all subarrays of nums of size k.

Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

 

Example 1:

Input: nums = [1,2,3,4,3,2,5], k = 3

Output: [3,4,-1,-1,-1]





class Solution {
public:
    bool check(int i, int j ,int k ,vector<int>&nums ){
        int m = i;
        k--;
        while(k--){
            // cout<<"m "<<m<<endl;
            if(m < nums.size() - 1 && nums[m] + 1 != nums[m+1]){
                return false;
            }
            m++;
        }
        return true;
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        int i =0 , j= 0, n = nums.size();
        while(j<n){
            if(j >= k-1){
              
                // cout<<i<<" i << "<<endl;
                // cout<<j<<" j << "<<endl;
                bool checkb = check(i,j,k,nums);
                // cout<<checkb<<"check <<"<<endl;

                if(checkb){
                    res.push_back(nums[j]);
                }else{
                    res.push_back(-1);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};
