Time Complexity :- O(NlogN)
Space Complexity :- O(N)
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
  
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l >= r) return;
        int mid = l + (r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
