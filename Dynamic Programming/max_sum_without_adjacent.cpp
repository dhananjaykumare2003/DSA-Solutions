Memoization:-
  Time Complexity :- O(n);
  Space Complexity :- O(n);
class Solution {
  public:
    int f(int n, vector<int>& arr, vector<int>& dp){
        if(n == 0) return arr[0];
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int pick = arr[n] + f(n-2,arr,dp);
        int notPick = 0 + f(n-1,arr,dp);
        return dp[n] = max(pick,notPick);
    }
    
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(n-1,arr,dp);
    }
};

Tabulation:-
  Time Complexity :- O(n);
  Space Complexity :- O(n);
class Solution {
  public:
    
    int findMaxSum(vector<int>& arr) {
        int n = arr.size()-1;
        vector<int> dp(n+1,-1);
        dp[0] = arr[0];
        for(int i = 1; i <= n; i++){
            int pick = arr[i];
            if(i > 1) pick += dp[i-2];
            int notPick = 0 + dp[i-1];
            dp[i] = max(pick,notPick);
        }
        return dp[n];
    }
};

Space Optimization in Tabulation:-
  Time Complexity :- O(n);
  Space Complexity :- O(1);
class Solution {
  public:
    
    int findMaxSum(vector<int>& arr) {
        int n = arr.size()-1;
        int prev2 = 0,prev = arr[0];
        for(int i = 1; i <= n; i++){
            int pick = arr[i];
            if(i > 1) pick += prev2;
            int notPick = 0 + prev;
            int curr = max(pick,notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
