MEMOIZATION :- Understanding through fibonacci
Time Complexity :- O(n)
Space Complexity :- O(n){recursion height} + O(n) {dp array}

Code:-
 int fib(int n, vector<int>& dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = fib(n-1,dp) + fib(n-2,dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    cout << fib(n,dp) << endl;
}

TABULATION :- converting recursion(top-down) to tabulation(bottom-up) approach
Time Complexity :- O(n)
Space Complexity :- O(n){dp array}

Code:-
  int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
}

Space Optimization in Tabulation :- instead of dp array we are using two variables to store prev elements

Code:-
  int main(){
    int n;
    cin >> n;
    int prev = 1,prev2 = 0,curr;
    for(int i = 2; i <= n; i++){
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout << curr;
}

