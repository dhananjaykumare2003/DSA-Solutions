Approach1:- generating all subarrays
Time Complexity :- O(N^2) considering map taking O(1)
Space Complexity :- O(N) 

Approach2:- two pointer and sliding window, and using concept (<= k) - (<= k-1)
Time Complexity :- 2*O(2N) considering map taking O(1)
Space Complexity :- O(N) 
class Solution {
public:
    int count(vector<int>& nums, int k){
        if(k == 0) return 0;
        int n = nums.size();
        int l = 0, r = 0, cnt = 0;
        map<int,int> mpp;
        while(r < n){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (count(nums,k) - count(nums,k-1));
    }
};
