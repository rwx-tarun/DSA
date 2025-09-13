1423. Maximum Points You Can Obtain from Cards

// - cannot apply Greedy here - later we might have a bigger solution 

// - we take the left sum & right sum 
// - we calculate the left sum as k left elements & right sum = 0 
// - now we decrease the left window by 1 & increase the right window by 1 
// - subtract the sum left & add to the right sum 
// - calculate the max sum in this return the result 



class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum=0 , rightSum=0;
        for(int i=0;i<k;i++){
            leftSum = leftSum + cardPoints[i];
        }
        int i=k-1,j=cardPoints.size()-1;
        int res = leftSum;
        while(k){
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[j];
            i--;
            j--;
            k--;
            res = max(res , leftSum + rightSum);
        }
        return res;
    }
};
