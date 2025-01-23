Approach-1 :- using 2 loops 
Time Complexity :- O(N^2)
Space Complexity :- O(1)
int inversionCount(vector<int> &arr) {
        int n = arr.size();
        int cnt = 0;
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < i; j++){
                if(arr[j] > arr[i])cnt++;
            }
        }
        return cnt;
  }

Approach-2:- some changes in merge sort
Time Complexity :- O(NlogN)
Space Complexity :- O(N)
int merge(vector<int>& arr,int l, int mid, int r){
        vector<int> temp;
        int i = l,j = mid + 1, k = l;
        int cnt = 0;
        while(i <= mid && j <= r){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i++]);
            }else{
                cnt += (mid-i+1);
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
        return cnt;
    }
  
    int mergeSort(vector<int>& arr, int l, int r) {
        int cnt = 0;
        if(l >= r) return cnt;
        int mid = l + (r-l)/2;
        cnt += mergeSort(arr,l,mid);
        cnt += mergeSort(arr,mid+1,r);
        cnt += merge(arr,l,mid,r);
        return cnt;
    }
    
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(arr,0, n-1);
    }
