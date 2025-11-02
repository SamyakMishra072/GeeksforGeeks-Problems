class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int first = -1, last = -1;
        int n = arr.size();
        for(int i=0; i<n; i++) {
            if (arr[i] == x) {
                first=i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--) {
            if(arr[i] == x) {
                last =i;
                break;
            }
        }
        
        return {first, last};
    }
};