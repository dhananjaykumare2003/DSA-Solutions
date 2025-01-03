Approach :- Tabulation (2D DP)
Time Complexity :- O(N*4)*3
Space Complexity :- O(N*4)
int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n,vector<int>(4,-1));
        dp[0][0] = max(arr[0][1],arr[0][2]);
        dp[0][1] = max(arr[0][0],arr[0][2]);
        dp[0][2] = max(arr[0][0],arr[0][1]);
        dp[0][3] = max(max(arr[0][0],arr[0][1]),arr[0][2]);
        for(int day = 1; day < n; day++){
            for(int last = 0; last < 4; last++){
                dp[day][last] = 0;
                for(int task = 0; task < 3; task++){
                    if(task != last){
                        int points = arr[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last],points);
                    }
                }
            }
        }
        return dp[n-1][3];
    }

Space Optimization:-
  int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<int> dp(4,0);
        dp[0] = max(arr[0][1],arr[0][2]);
        dp[1] = max(arr[0][0],arr[0][2]);
        dp[2] = max(arr[0][0],arr[0][1]);
        dp[3] = max(max(arr[0][0],arr[0][1]),arr[0][2]);
        for(int day = 1; day < n; day++){
            vector<int> temp(4,0);
            for(int last = 0; last < 4; last++){
                temp[last] = 0;
                for(int task = 0; task < 3; task++){
                    if(task != last){
                        int points = arr[day][task] + dp[task];
                        temp[last] = max(temp[last],points);
                    }
                }
            }
            dp = temp;
        }
        return dp[3];
    }
