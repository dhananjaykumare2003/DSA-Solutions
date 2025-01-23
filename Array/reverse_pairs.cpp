Approach-1 :- brute force using 2 loops
Time Complexity :- O(N^2)
Space Complexity :- O(1)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if((long long)nums[i] > 2 * (long long)nums[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

Approach-2 :- mergesort with slightly changed version
Time Complexity :- 2O(NlogN)
Space Complexity :- O(N)

class Solution {
public:
    void merge(vector<int>& arr,int l, int mid, int r){
        vector<int> temp;
        int i = l,j = mid + 1, k = l;
        while(i <= mid && j <= r){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i++]);
            }else{
                temp.push_back(arr[j++]);
            }
        }
        while(i <= mid){
            temp.push_back(arr[i++]);
        }
        while(j <= r){
            temp.push_back(arr[j++]);
        }
        for(int i = l; i <= r; i++){
            arr[i] = temp[i-l];
        }
        return;
    }

    int countPairs(vector<int>& arr, int l, int mid, int r){
        int right = mid+1;
        int cnt = 0;
        for(int i = l; i <= mid; i++){
            while(right <= r && (long long)arr[i] > 2 * (long long)arr[right]){
                right++;
            }
            cnt += (right-(mid+1));
        }
        return cnt;
    }
  
    int mergeSort(vector<int>& arr, int l, int r) {
        int cnt = 0;
        if(l >= r) return cnt;
        int mid = l + (r-l)/2;
        cnt += mergeSort(arr,l,mid);
        cnt += mergeSort(arr,mid+1,r);
        cnt += countPairs(arr,l,mid,r);
        merge(arr,l,mid,r);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums,0,n-1);
    }
};
