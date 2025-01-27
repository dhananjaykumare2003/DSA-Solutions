Approach :- i have stored the maxIndex that i can reach if index is greater than maxIndex we will return false otherwise we can reach.
Time Complexity :- O(N)
Space Complexity :- O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0;
        for(int i = 0; i < n; i++){
            if(i > maxIndex) return false;
            maxIndex = max(maxIndex, i + nums[i]);
            if(maxIndex >= n-1) return true;
        }
        return true;
    }
};
