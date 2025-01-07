Memoization :- my own approach last to starting point recursion
TC :- O(N*M) approx
SC :- O(N) + O(N*M)
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return triangle[i][j];
        if(i < 0 || j < 0 || j >= i+1) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        int up = f(i-1,j,triangle,dp);
        int upLeft = f(i-1,j-1,triangle,dp);
        return dp[i][j] = triangle[i][j] + min(up,upLeft);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int mini = INT_MAX;
        int size = triangle.size();
        vector<vector<int>> dp(size,vector<int>(size,-1));
        for(int i = 0; i < size; i++){
            mini = min(mini, f(size-1,i,triangle,dp));
        }
        return mini;
    }
};

Memoization :- i come to know that whenever starting point is fixed and ending points are variable then we should start recursion from starting point
TC :- O(N*M) approx
SC :- O(N) + O(N*M)
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        int n = triangle.size();
        if(i == n-1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        int d = f(i+1,j,triangle,dp);
        int dg = f(i+1,j+1,triangle,dp);
        return dp[i][j] =  triangle[i][j] + min(d,dg);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return f(0,0,triangle,dp);
    }
};

Tabulation :- to reduce recursion stack space 
TC :- O(N*M) approx
SC :- O(N*M)
  class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int j = 0; j < n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i = n-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int d = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d,dg);
            }
        }
        return dp[0][0];
    }
};

Space Optimisation :- To reduce additional space
TC :- O(N*M) approx
SC :- O(M)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n,-1);
        for(int j = 0; j < n; j++){
            dp[j] = triangle[n-1][j];
        }
        for(int i = n-2; i >= 0; i--){
            vector<int> temp(n,-1);
            for(int j = i; j >= 0; j--){
                int d = triangle[i][j] + dp[j];
                int dg = triangle[i][j] + dp[j+1];
                temp[j] = min(d,dg);
            }
            dp = temp;
        }
        return dp[0];
    }
};
