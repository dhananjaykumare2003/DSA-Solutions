Memoization:-
  class Solution {
public:
    int f(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(i == 0 && j == 0 && obstacleGrid[0][0] != 1) return 1;
        if(i < 0 || j < 0) return 0;
        if(obstacleGrid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left = 0,up = 0;
        up = f(i-1,j,obstacleGrid,dp);
        left = f(i,j-1,obstacleGrid,dp);
        return dp[i][j] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,obstacleGrid,dp);
    }
};

Tabulation:-
  class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        if(obstacleGrid[0][0]){
            dp[0][0] = 0;
        }else{
            dp[0][0] = 1;
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i >= 0 && j >= 0 && obstacleGrid[i][j]) dp[i][j] = 0;
                else if(i == 0 && j== 0) dp[i][j] = 1; 
                else{
                    int left = 0, up = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

Space Optimization:-
  class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n,0);
        for(int i = 0; i < m; i++){
            vector<int> temp(n,0);
            for(int j = 0; j < n; j++){
                if(i >= 0 && j >= 0 && obstacleGrid[i][j]) temp[j] = 0;
                else if(i == 0 && j== 0) temp[j] = 1; 
                else{
                    int left = 0, up = 0;
                    if(i > 0) up = dp[j];
                    if(j > 0) left = temp[j-1];
                    temp[j] = up + left;
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};
