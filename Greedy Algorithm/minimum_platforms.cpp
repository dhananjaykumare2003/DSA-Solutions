Approach-1:- finding overlapping time for each train
Time Complexity :- O(N^2)
Space Complexity :- O(1)

Approach-2:- Greedy Algorithm, arranged as the time passes
Time Complexity :- 2O(NlogN + N)
Space Complexity :- O(1)

class Solution {
  public:

    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i = 0, j = 0, cnt = 0, maxcnt = 0;
        while(i < n){
            if(arr[i] <= dep[j]){
                cnt++;
                i++;
            }else{
                cnt--;
                j++;
            }
            maxcnt = max(cnt, maxcnt);
        }
        return maxcnt;
    }
};
