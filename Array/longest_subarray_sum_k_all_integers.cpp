Brute Force Approach :- generating all subarrays
Time Complexity :- O(N^2)
Space Complexity :- O(1)
  
int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(), len = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i;j < n; j++){
                sum += arr[j];
                if(sum == k){
                    len = max(len,j-i+1);
                }
            }
        }
        return len;
    }

Approach 2:- using hashMap
Time Complexity :- O(NlogN)
Space Complexity :- O(N)

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(), sum = 0, len = 0;
        map<int,int> mpp;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == k){
                len = max(len, i+1);
            }
            int rem = sum - k;
            if(mpp.find(rem) != mpp.end()){
                len = max(len, i - mpp[rem]);
            }
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return len;
    }
};
