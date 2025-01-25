Approach-1 :- generating all subarrays and counting the subarrays with sum == goal.
Time Complexity :- O(N^2)
Space Complexity :- O(1)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                if(sum > goal) break;
                if(sum == goal) cnt++;
            }
        }
        return cnt;
    }
};

Approach-2 :- prefixSum technique using hashMap.
Time Complexity :- O(N)
Space Complexity :- O(N)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        map<int, int> mpp;
        int sum = 0, cnt = 0;
        mpp[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];;
            int rem = sum-goal;
            cnt += mpp[rem];
            mpp[sum]++;
        }
        return cnt;
    }
};

Approach-3 :- using two pointer and sliding window
Time Complexity :- O(2*2N)
Space Complexity :- O(1)
class Solution {
public:
    int count(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int n = nums.size();
        int l = 0, r = 0, cnt = 0, sum = 0;
        while(r < n){
            sum += nums[r];
            while(sum > goal) sum -= nums[l++];
            if(sum <= goal) cnt += (r-l+1);
            r++;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return (count(nums,goal) - count(nums,goal-1));
    }
};
