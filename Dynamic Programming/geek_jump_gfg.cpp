Approach :- 1D DP - Memoization
T.C. :- O(n)
S.C. :- O(n)

Code:-
int f(int n,vector<int>& height, vector<int>& dp){
        if(n == 0) return 0;
        if(n == 1) return abs(height[1]-height[0]);
        if(dp[n] != -1) return dp[n];
        int left = f(n-1,height,dp) + abs(height[n]-height[n-1]);
        int right = f(n-2,height,dp) + abs(height[n]-height[n-2]);
        return dp[n] = min(left,right);
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        return f(n-1,height,dp);
    }
