Approach-1:- generating all subarrays and for distinct numbers we used set
Time Complexity :- O(N^2)
Space Complexity :- O(1)
int totalElements(vector<int> &arr) {
        int n = arr.size();
        int maxlen = 0;
        for(int i = 0; i < n; i++){
            set<int> st;
            for(int j = i; j < n; j++){
                st.insert(arr[j]);
                if(st.size() <= 2){
                    maxlen = max(maxlen, j-i+1);
                }else{
                    break;
                }
            }
        }
        return maxlen;
}

Approach-2:- sliding window and two pointers, here we have to use map instead of set data structure because while shrinking we need to reduce cnt, we can't erase the number directly.
Time Complexity :- O(2N)
Space Complexity :- O(1)
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        map<int,int> mpp;
        int l = 0, r = 0, maxlen = 0;
        while(r < n){
            mpp[arr[r]]++;
            while(mpp.size() > 2){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
                l++;
            }
            if(mpp.size() <= 2){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};

Approach-3:- sliding window and two pointers with slight change.
Time Complexity :- O(2N)
Space Complexity :- O(1)
class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        map<int,int> mpp;
        int l = 0, r = 0, maxlen = 0;
        while(r < n){
            mpp[arr[r]]++;
            if(mpp.size() > 2){
                mpp[arr[l]]--;
                if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
                l++;
            }
            if(mpp.size() <= 2){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }
        return maxlen;
    }
};
