// TC - O(2*n)
// SC - O(1)

// take the sum 
// check if it overflows 
// calculate the sum when the window is correct 

void maxSubarray(vector<int>arr){
  int i,j=0;
  int res = 0,sum=0;
  while(j<arr.size()){
    sum =sum + arr[j];
    while(sum > k){
      sum = sum - arr[i];
      i++;
    }
    res = max(res , (j-i+1));
  }
  return res;
}

