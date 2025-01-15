Approach :- traversing from back and checking for maximum element
Time Complexity :- O(N)
Space Complexity :- O(1)

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        int maxi = -1;
        for(int i = n-1; i >= 0; i--){
            maxi = max(maxi,arr[i]);
            if(maxi == arr[i]) ans.push_back(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
