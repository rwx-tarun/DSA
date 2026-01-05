First negative in every window of size k
Difficulty: MediumAccuracy: 48.61%Submissions: 216K+Points: 4Average Time: 15m
Given an array arr[]  and a positive integer k, find the first negative integer for each and every window(contiguous subarray) of size k.

Note: If a window does not contain a negative integer, then return 0 for that window.

Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window [-8, 2] First negative integer is -8.
Window [2, 3] No negative integers, output is 0.
Window [3, -6] First negative integer is -6.
Window [-6, 10] First negative integer is -6.

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {      
        deque<int> q;
        int i =0 , j =0 , n = arr.size();
        vector<int>res;
        while(j<n){
            if(arr[j] < 0){
                q.push_back(j);
            }
            if(j-i+1 > k){
                if(!q.empty()  && q.front()  == i){
                    q.pop_front();
                }
                i++;
            }
            if(j-i+1 == k){
                res.push_back(q.empty() ? 0 : arr[q.front()]);
            }
            j++;
        }
        return res;
    }
};
