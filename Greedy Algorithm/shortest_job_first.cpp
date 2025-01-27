Approach :- Greedy Algorithm because we are executing least waiting time processes first sequencially.
Time Complexity :- O(NlogN) + O(N)
Space Complexity :- O(1)
class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(),bt.end());
        long long time = 0, wts = 0; //wts == waiting time sum
        for(int i = 0; i < n; i++){
            wts += time;
            time += bt[i];
        }
        return (wts/n);
    }
};
