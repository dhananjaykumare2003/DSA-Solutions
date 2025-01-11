TC :- O(N)
SC :- O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0,cnt = 0,n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                cnt++;
            }else{
                cnt = 0;
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};
