Logic we are using is that we convert or assuming the question as we need to find the longest subarray with max zeroes as k

Approach-1 :- generating all subarrays
Time Complexity :- O(N^2)
Space Complexity :- O(1)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = i; j < n; j++){
                if(nums[j] == 0){
                    cnt++;
                    if(cnt > k) break;
                }
                maxlen = max(maxlen, j-i+1);
            }
        }
        return maxlen;
    }
};

Approach-2 :- using sliding window and two pointer technique
Time Complexity :- O(2N)
Space Complexity :- O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0, r = 0, l = 0,maxlen = 0;
        while(r < n){
            if(nums[r] == 0) cnt++;
            while(cnt > k){
                if(nums[l] == 0) cnt--;
                l++;
            }
            if(cnt <= k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

Approach-3 :- using sliding window and two pointer technique with slight change in approach2, we are not trimming window until we find zero, we are just trimming it upto maxlen.
Time Complexity :- O(N)
Space Complexity :- O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeros = 0, r = 0, l = 0,maxlen = 0;
        while(r < n){
            if(nums[r] == 0) zeros++;
            if(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }
            if(zeros <= k) maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};
