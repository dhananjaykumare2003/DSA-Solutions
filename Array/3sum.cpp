Brute Force Approach :- take any three elements and check whether there sum is equal to 0
Time Complexity :- O(N*3)
Space Complexity :- O(V) where V is no of triplets
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        int n = nums.size();
        for(int i = 0; i < n-2; i++){
            for(int j = 1; j < n-1; j++){
                for(int k = 2; k < n; k++){
                    if(nums[i] + nums[j] + nums[k] == 0 && i != j && j != k && i != k){
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    };
                }
            }
        }
        for(auto it : st){
            ans.push_back(it);
        }
        return ans;
    }
};

Approach 2:- using hashset
Time Complexity :- O(N*2*logM) where M is size of set
Space Complexity :- O(N) + O(V) where V is no of triplets
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            set<int> hashset;
            for(int j = i+1; j < n; j++){
                int rem = 0-nums[i]-nums[j];
                if(hashset.find(rem) != hashset.end()){
                    vector<int> temp = {nums[i], nums[j], rem};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};

Approach 3 :- 2 pointer technique
Time Complexity :- O(NlogN) + O(N^2)
Space Complexity :- O(V) for ans return, where V is no of triplets 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0){
                    k--;
                }else if(sum < 0){
                    j++;
                }else{
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};
