Approach :- Brute Force Approach
Time Complexity :- O(N^2)
Space Complexity :- O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            for(int j = 1; j < n; j++){
                if(nums[i] + nums[j] == target) return {i,j};
            }
        }
        return {-1,-1};
    }
};


Approach :- Using HashMap
Time Complexity :- O(NlogN)
Space Complexity :- O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        map<int,int> mpp;
        mpp[nums[0]] = 0;
        for(int i = 1; i < n; i++){
            int rem = target-nums[i];
            if(mpp.find(rem) != mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[rem]);
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};
