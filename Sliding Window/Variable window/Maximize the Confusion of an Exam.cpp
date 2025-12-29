
2024. Maximize the Confusion of an Exam
Solved
Medium
Topics
premium lock icon
Companies
Hint
A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

 


class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int cnt =0;
        int res = 0;
        int i=0,j=0,n = answerKey.length();
        while(j<n){
            if(answerKey[j] == 'T'){
                cnt++;
            }
            while(cnt > k){
                if(answerKey[i] == 'T'){
                    cnt--;
                }
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        i=0,cnt=0,j=0;
        while(j<n){
            if(answerKey[j] == 'F'){
                cnt++;
            }
            while(cnt > k){
                if(answerKey[i] == 'F'){
                    cnt--;
                }
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};
