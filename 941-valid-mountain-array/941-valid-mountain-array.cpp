class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 0, j = arr.size()-1;
        while(i < arr.size()-1 && arr[i+1]>arr[i]){
            i++;
        }
        while(j > 0 && arr[j-1] > arr[j]){
            j--;
        }
        return i > 0 && j < arr.size() - 1 && i == j;
    }
};
