Approach :- 
i> check from back there exist any index for which A[i] < A[i+1],store that index, if there is no such index present than we will return the sorted array.
ii> check from back and swap last greatest element than the number present at this index.
iii> reverse array from ind+1 to n-1.
Time Complexity :- O(N)
Space Complexity :- O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),ind = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1) sort(nums.begin(),nums.end());
        else{
            for(int i = n-1; i >= ind; i--){
                if(nums[ind] < nums[i]){
                    swap(nums[ind],nums[i]);
                    break;
                }
            }
            reverse(nums.begin()+ind+1,nums.end());
        }
    }
};
