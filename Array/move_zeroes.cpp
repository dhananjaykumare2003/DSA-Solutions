Approach :- Two Pointer Approach to bring all non zero elements to left and zeroes to right
Time Complexity :- O(N)
Space Complexity :- O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                swap(nums[j++],nums[i]);
            }
        }
    }
};
