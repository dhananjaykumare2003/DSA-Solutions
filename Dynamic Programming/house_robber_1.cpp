Memoization :- T.C :- O(N),S.C :- O(2N){stake height,dp array}

class Solution {
public:
    int f(int n,vector<int>& nums, vector<int>& dp){
        if(n == 0) return nums[0];
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int take = nums[n] + f(n-2,nums,dp);
        int notTake = 0 + f(n-1,nums,dp);
        return dp[n] = max(take,notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
};

Tabulation:- T.C :- O(N), S.C :- O(N)
  
  class Solution {
  public:

    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+1,-1);
        dp[0] = nums[0];
        for(int i = 1; i <= n; i++){
            int take = nums[i];
            if(i > 1) take += dp[i-2];
            int notTake = 0 + dp[i-1];
            dp[i] = max(take,notTake);
        }
        return dp[n];
    }
};

Space Optimization :- T.C :- O(N), S.C :- O(1)

  class Solution {
  public:

    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        int prev = nums[0],prev2 = 0;
        for(int i = 1; i <= n; i++){
            int take = nums[i];
            if(i > 1) take += prev2;
            int notTake = 0 + prev;
            int curr = max(take,notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
