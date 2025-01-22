Approach-1:- generating all subarrays
Time Complexity :- O(N^2)
Space Complexity :- O(1)

Approach-2:- using prefixSum technique
Time Complexity :- O(NlogN)
Space Complexity :- O(N)
  
int maxLen(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        map<int,int> mpp;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == 0) maxi = max(maxi,i+1);
            int rem = sum - 0;
            if(mpp.find(rem) != mpp.end()){
                maxi = max(maxi, i-mpp[rem]);
            }
            if(mpp.find(sum) == mpp.end()){
                mpp[sum] = i;
            }
        }
        return maxi;
    }
