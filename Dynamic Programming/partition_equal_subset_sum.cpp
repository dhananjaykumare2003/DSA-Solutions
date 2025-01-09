Memoization:-
  class Solution {
public:
    bool f(int n,int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(n == 0) return (target == nums[0]);
        if(dp[n][target] != -1) return dp[n][target];
        bool take = false;
        if(nums[n] <= target){
            take = f(n-1,target-nums[n],nums,dp);
        }
        bool notTake = f(n-1,target,nums,dp);
        return dp[n][target] = take | notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0,total = 0,target = 0,n = nums.size();
        for(int i = 0; i < n; i++){
            total += nums[i];
        }
        if(total % 2 == 1) return false;
        target = total/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,nums,dp);
    }
};

Tabulation:-
  class Solution {
public:
    bool targetSum(int n,int target,vector<int>& nums){
        vector<vector<bool>> dp(n,vector<bool>(target+1,0));
        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }
        if(target >= nums[0]) dp[0][nums[0]] = 1;
        for(int i = 1; i < n; i++){
            for(int k = 1; k <= target; k++){
                bool take = false;
                if(nums[i] <= k){
                    take = dp[i-1][k-nums[i]];
                }
                bool notTake = dp[i-1][k];
                dp[i][k] = take | notTake;
            }
        }
        return dp[n-1][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0,total = 0,target = 0,n = nums.size();
        for(int i = 0; i < n; i++){
            total += nums[i];
        }
        if(total % 2 == 1) return false;
        target = total/2;
        return targetSum(n,target,nums);
    }
};

Space Optimisation:-
  class Solution {
public:
    bool targetSum(int n,int target,vector<int>& nums){
        vector<bool> prev(target+1,0),cur(target+1,0);
        prev[0] = cur[0] = 1;
        if(target >= nums[0]) prev[nums[0]] = 1;
        for(int i = 1; i < n; i++){
            for(int k = 1; k <= target; k++){
                bool take = false;
                if(nums[i] <= k){
                    take = prev[k-nums[i]];
                }
                bool notTake = prev[k];
                cur[k] = take | notTake;
            }
            prev = cur;
        }
        return prev[target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0,total = 0,target = 0,n = nums.size();
        for(int i = 0; i < n; i++){
            total += nums[i];
        }
        if(total % 2 == 1) return false;
        target = total/2;
        return targetSum(n,target,nums);
    }
};
