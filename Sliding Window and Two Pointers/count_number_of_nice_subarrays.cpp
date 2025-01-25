Approach-1:- generating all subarrays
Time Complexity :- O(N^2)
Space Complexity :- O(1);
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = i; j < n; j++){
                if(nums[j] % 2 == 1) cnt++;
                if(cnt > k) break;
                if(cnt == k) ans++;
            }
        }
        return ans;
    }
};

Approach-2:- two pointer and sliding window, considering it similar to binary subarray with sum problem
Time Complexity :- O(N);
Space Complexity :- O(1);
class Solution {
public:
    int count(vector<int>& nums, int k){
        int n = nums.size();
        int l = 0, r = 0, cnt = 0, sum = 0;
        while(r < n){
            sum += (nums[r]%2);
            while(sum > k){
                sum -= (nums[l]%2);
                l++;
            }
            if(sum <= k){
                cnt += (r-l+1);
            }
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return (count(nums,k) - count(nums,k-1));
    }
};
