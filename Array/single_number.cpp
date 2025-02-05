Approach :- XOR is used to remove duplicacy
Time Complexity :- O(N)
Space Complexity :- O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};
