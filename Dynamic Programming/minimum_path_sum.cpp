Memoization:-
  TC :- O(N*M)
  SC :_ O(N*M) + {O(M-1) + O(N-1)} recursion stack equal to path length
  class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int left = f(i,j-1,grid,dp);
        int up = f(i-1,j,grid,dp);
        return dp[i][j] = grid[i][j] + min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,grid,dp);
    }
};

Tabulation:-
  TC :- O(N*M)
  SC :_ O(N*M)
  class Solution {
public:
    int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i == 0 && j == 0) return grid[0][0];
        if(i < 0 || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int left = f(i,j-1,grid,dp);
        int up = f(i-1,j,grid,dp);
        return dp[i][j] = grid[i][j] + min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0] = grid[0][0];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if(i > 0 || j > 0){
                    int left = INT_MAX, up = INT_MAX; 
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = grid[i][j] + min(left,up);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

Space Optimization:-
  TC :- O(N*M)
  SC :_ O(N)
  class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,0);
        dp[0] = grid[0][0];
        for(int i = 0; i < m; i++){
            vector<int> temp(n,0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) temp[j] = grid[i][j];
                else{
                    int up = grid[i][j],left = grid[i][j];
                    if(i > 0) up += dp[j];
                    else up = 1e9;
                    if(j > 0) left += temp[j-1];
                    else left = 1e9;
                    temp[j] = min(left,up);
                }
            }
            dp = temp;
        }
        return dp[n-1];
    }
};
