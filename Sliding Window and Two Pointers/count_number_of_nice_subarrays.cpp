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
