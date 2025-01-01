Approach :- DP similar to fibonacci
T.C. :- O(N)
S.C. :- O(2N)
Code :-
class Solution {
public:
    int f(int n, vector<int>& dp){
        if(n == 1 || n == 2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = f(n-1,dp) + f(n-2,dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};
