Approach :- Using hashmap
Time Complexity :- O(N*1) best case(generally) or O(N*N) worst case of unordered_map
Space Complexity :- O(N)
Learnings :- if we don't required ordered values we will prefer unordered_map because its time complexity is O(1) generally

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0,sum = 0;
        unordered_map<int,int> prefixSum;
        prefixSum[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(prefixSum.find(sum - k) != prefixSum.end()){
                cnt += prefixSum[sum-k];
            } 
            prefixSum[sum] += 1;
        }
        return cnt;
    }
};
