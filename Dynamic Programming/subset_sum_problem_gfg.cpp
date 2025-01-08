All the solutions are correct but getting TLE for large cases even the optimized one, may be there is some problem with constraints(don't know why?>

Memoization:-
bool f(int i,vector<int>& arr, int target,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i == 0) return (arr[0] == target);
        if(dp[i][target] != -1) return dp[i][target];
        int notTake = f(i-1,arr,target,dp);
        int take = false;
        if(target >= arr[i]){
            take = f(i-1,arr,target-arr[i],dp);
        }
        return dp[i][target] = (take | notTake);
    }
bool isSubSet(vector<int>&arr, int target) {
  int n = arr.size();
  vector<vector<int>>& dp(n,vector<int>(target+1,-1));
  return f(n-1,arr,target,dp);
}


Tabulation:-
class Solution {
  public:
  
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        if(arr[0] <= target) dp[0][arr[0]] = 1;
        for(int i = 1; i < n; i++){
            for(int k = 1; k <= target; k++){
                bool notTake = dp[i-1][k];
                bool take = false;
                if(k >= arr[i]){
                    take = dp[i-1][k-arr[i]];
                }
                dp[i][k] = (take | notTake);
            }
        }
        return dp[n-1][target];
    }
};

Space Optimisation:-
bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<bool> prev(target+1,false);
        vector<bool> cur(target+1,false);
        prev[0] = cur[0] = 1;
        prev[arr[0]] = 1;
        for(int i = 1; i < n; i++){
            for(int k = 1; k <= target; k++){
                bool notTake = prev[k];
                bool take = false;
                if(k >= arr[i]){
                    take = prev[k-arr[i]];
                }
                cur[k] = (take | notTake);
            }
            prev = cur;
        }
        return prev[target];
    }
