Approach :- Memoization (2D DP)
Time Complexity :- O(N*4) * 3
Space Complexity :- O(N) + O(N*4)
int f(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(day == 0){
            int maxi = 0;
            for(int task = 0; task < 3; task++){
                if(task != last){
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }
        if(dp[day][last] != -1) return dp[day][last];
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last){
                int points = arr[day][task] + f(day-1,task,arr,dp);
                maxi = max(maxi, points);
            }
        }
        return dp[day][last] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return f(n-1,3,arr,dp);
    }
