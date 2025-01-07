Memoization:- But it got TLE
TC :- O(N*N)
SC :- O(N) + O(N*N)
class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i < 0 || j < 0 || i >= n || j >= n) return 1e9;
        if(i == n-1) return matrix[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int dgl = f(i+1,j-1,n,matrix,dp);
        int d = f(i+1,j,n,matrix,dp);
        int dgr = f(i+1,j+1,n,matrix,dp);
        return dp[i][j] = matrix[i][j] + min(d,min(dgl,dgr));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int i = 0; i < n; i++){
            ans = min(ans,f(0,i,n,matrix,dp));
        }
        return ans;
    }
};

Tabulation
TC :- O(N*N)
SC :- O(N*N)
class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 1e9;
        vector<vector<int>> dp(n, vector<int>(n,1e9));
        for(int j = 0; j < n; j++){
            dp[n-1][j] = matrix[n-1][j];
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                int dgl = 1e9,d = 1e9, dgr = 1e9;
                    if(j-1 >= 0) dgl = dp[i+1][j-1];
                    d = dp[i+1][j];
                    if(j+1 < n) dgr = dp[i+1][j+1];
                    dp[i][j] = matrix[i][j] + min(d,min(dgl,dgr));
            }
        }
        for(int j = 0; j < n; j++){
            ans = min(ans,dp[0][j]);
        }
        return ans;
    }
};

Space Optimization
TC :- O(N*N)
SC :- O(N)
class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 1e9;
        vector<int> dp(n,1e9);
        for(int j = 0; j < n; j++){
            dp[j] = matrix[n-1][j];
        }
        for(int i = n-2; i >= 0; i--){
            vector<int> temp(n,1e9);
            for(int j = n-1; j >= 0; j--){
                int dgl = 1e9,d = 1e9, dgr = 1e9;
                    if(j-1 >= 0) dgl = dp[j-1];
                    d = dp[j];
                    if(j+1 < n) dgr = dp[j+1];
                    temp[j] = matrix[i][j] + min(d,min(dgl,dgr));
            }
            dp = temp;
        }
        for(int j = 0; j < n; j++){
            ans = min(ans,dp[j]);
        }
        return ans;
    }
};
