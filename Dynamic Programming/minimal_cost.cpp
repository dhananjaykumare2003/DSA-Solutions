Memoization:-
class Solution {
  public:
    int f(int n,int k,vector<int>& arr, int mini,vector<int>& dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        for(int i = 1; i <= k; i++){
            if(n >= i){
                mini = min(mini, f(n-i,k,arr,mini,dp) + abs(arr[n] - arr[n-i]));
            }
        }
        return dp[n] = mini;
    }
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MAX;
        vector<int> dp(n,-1);
        return f(n-1,k,arr,mini,dp);
    }
};

Tabulation :-
int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size()-1;
        int mini = INT_MAX;
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                if(n >= j){
                    int jump = f(n-j,k,arr,mini,dp) + abs(arr[n] - arr[n-j]);
                    mini = min(mini,jump);
                }
            }
            dp[i] = mini;
        }
        return dp[n];
    }
