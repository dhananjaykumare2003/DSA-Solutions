Approach 1:- Generate all subarray and check for max sum
Time Complexity:- O(N^3) which we can bring to O(N^2) by some changes
Space Complexity:- O(1)

  
Approach 2:- Kadane's Algorithm where we won't carry forward negative values in sum because it will always give smallest sum as compare to not taking it.
Time Complexity:- O(N)
Space Complexity:- O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0],n = nums.size(),sum = 0;
        for(int i = 0; i < n; i++){
          // if you want to print also then    if(sum == 0) start = i;
            sum += nums[i];
            maxi = max(maxi,sum);             //if(maxi < sum ){ maxi = sum, ansStart = start, ansEnd = i};// psuedo code
            if(sum < 0) sum = 0;
        }
        return maxi;
    }
};
