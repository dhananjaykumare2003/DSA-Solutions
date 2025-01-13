Approach :- logic that any subarray whose smallest and second smallest elements sum is maximum only possible if we take two consecutive maximum elements
Time Complexity :- O(N)
Space Complexity :- O(1)
class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        int msum = 0,n = arr.size();
        for(int i = 0; i < n-1; i++){
            int sum = arr[i] + arr[i+1];
            msum = max(msum,sum);
        }
        return msum;
    }
};
