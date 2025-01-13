Approach-1 :- sort then cnt and find maxcnt element
Time Complexity:- O(NlogN) (for sort) + O(N) (for traverse)
Space Complexity:- O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 1,maxcnt = 1,element = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]){
                cnt++;
            }
            if(nums[i] > nums[i-1]){ 
                cnt = 1;
            }
            if(cnt >= maxcnt){
                maxcnt = cnt;
                element = nums[i-1];
            }
        }
        return element;
    }
};


Approach-2:- Logic that major element cnt++ and other element cnt--
Time Complexity:- O(N)
Space Complexity:- O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element;
        int n = nums.size(),cnt = 0;
        for(int i = 0; i < n; i++){
            if(cnt == 0){
                element = nums[i];
                cnt++;
            }else if(nums[i] == element){
                cnt++;
            }else{
                cnt--;
            }
        }
        return element;
    }
};
