Memoization
TC :- O(N*M)
SC :- O(N*M) + O(N-1) + O(M-1)
class Solution {
public:
    int f(int i, int j,int m, int n,vector<vector<int>>& dp){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left = f(i-1,j,m,n,dp);
        int up = f(i,j-1,m,n,dp);
        return dp[i][j] = left+up;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return f(m-1,n-1,m,n,dp);
    }
};

Tabulation
TC :- O(N*M)
SC :- O(N*M)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        dp[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int up = 0,left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
                
            }
        }
        return dp[m-1][n-1];
    }
};

Space Optimization
TC :- O(N*M)
SC :- O(N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i = 0; i < m; i++){
            vector<int> temp(n,0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) temp[j] = 1;
                else{
                    int up = 0,left = 0;
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
