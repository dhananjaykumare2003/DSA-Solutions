APPROACH-1 :- use the concept of modulus on size of array ex. temp[(i%k)%n] = nums[i]

  Time Complexity : O(n)
  Space Complexity : O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            temp[(i+k)%n] = nums[i];
        }
        nums = temp;
    }
};


APPROACH-2 :- Reverse the array, then reverse subarrays from 0 to k-1 and then from k to end(Total 3 times reverse)
  Time Complexity : O(n)
  Space Complexity : O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
  
