Approach :- Two Pointer
Time Complexity :- O(N)
Space Complexity :- O(1)
  
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = n-1, k = n-1;
        while(i <= j){
            if(nums[j] == 0){
                swap(nums[i++],nums[j]);
            }
            else{
                j--;
            }
        }
        while(i < k){
            if(nums[k] == 1){
                swap(nums[i++],nums[k]);
            }else{
                k--;
            }
        }
        return;
    }
};
