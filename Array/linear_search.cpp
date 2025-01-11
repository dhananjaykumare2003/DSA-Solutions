TC :- O(N)
SC :- O(1)
class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // k: element to be searched
    bool searchInSorted(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(k == arr[i]){
                return true;
            }
        }
        return false;
    }
};

Optimized Solution:-
TC :- O(logN)
SC :- O(1)
bool searchInSorted(vector<int>& arr, int k) {
        int n = arr.size();
        int i = 0,j = n-1;
        int mid = i + (j-i)/2;
        while(i <= j){
            mid = i + (j-i)/2;
            if(arr[mid] == k) return true;
            else if(arr[mid] > k) j = mid-1;
            else i = mid + 1;
        }
        return false;
    }
