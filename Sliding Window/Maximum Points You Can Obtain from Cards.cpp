Maximum Points You Can Obtain from Cards
Medium

Hints
Company
Given N cards arranged in a row, each card has an associated score denoted by the cardScore array.
Choose exactly k cards. In each step, a card can be chosen either from the beginning or the end of the row. The score is the sum of the scores of the chosen cards.
Return the maximum score that can be obtained.

Example 1
Input : cardScore = [1, 2, 3, 4, 5, 6] , k = 3
Output : 15
Explanation : Choosing the rightmost cards will maximize your total score. So optimal cards chosen are the rightmost three cards 4 , 5 , 6.
The score is 4 + 5 + 6 => 15.



Brute force try all possibility 

1. Sum from start k element 
2. reduce from start one & add one from end 
3. repeat till k return the answer 



class Solution{
  public:
    int maxScore(vector<int>& cardScore , int k){
        int n = cardScore.size();
        int res = 0;
        int i =0 , j=n-1;
        for(i=0;i<k;i++){
          res = res + cardScore[i];
        }
        int mx = res;
        i--;
        while(k--){
          res = res - cardScore[i];
          res = res + cardScore[j];
          i--;
          j--;
          mx = max(mx , res);
        }
        return mx;
    }
};
