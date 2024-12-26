class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int l1 = -1,l2 = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] > l1){
                l2 = l1;
                l1 = arr[i];
            } 
            else if(arr[i] < l1 && arr[i] > l2){
                l2 = arr[i];
            }
        }
        return l2;
    }
};
