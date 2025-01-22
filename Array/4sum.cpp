Approach-1:- brute force using four loops selecting 4 different elements
Time Complexity :- O(N^4)
Space Complexity :- O(M) where M is no. of qradruplets

Approach-2:- using hashset
Time Complexity :- O(N^3*logN)
Space Complexity :- O(M) where M is no. of qradruplets

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j<n; j++){
                set<long long> hashset;
                for(int k = j+1; k < n; k++){
                    long long sum = nums[i]+nums[j];
                    sum += nums[k];
                    long long rem = target- sum;
                    if(hashset.find(rem) != hashset.end()){
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)rem};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    hashset.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;   
    }
};

Approach-3:- Two Pointer technique in four variable considering first two variables i, j as constant
Time Complexity :- O(N^3)
Space Complexity :- O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while(k < l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum > target) l--;
                    else if(sum < target) k++;
                    else{
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++, l--;
                        while(k < l && nums[k] == nums[k-1]) k++;
                        while(k < l && nums[l] ==  nums[l+1]) l--;
                    }
                }
            } 
        }
        return ans;
    }
};
