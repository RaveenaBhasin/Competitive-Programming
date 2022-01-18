class Solution {
public:
    int countCandies(vector<int>&arr, int n){
        int sum = 0;
        vector<int>ans(n, 1);
        for(int i = 0; i < n-1; i++){
            if(arr[i+1] > arr[i] && ans[i+1] <= ans[i]){
                ans[i+1] = ans[i] + 1;
            }
        }
        for(int i = n-2; i >= 0; i--){
            if(arr[i+1] < arr[i] && ans[i+1] >= ans[i]){
                ans[i] = ans[i+1] + 1;
            }
            sum += ans[i];
        }
        // for(auto it: ans){
        //     cout<<it<<" ";
        // }
        // cout<<"\n";
        sum += ans[n-1];
        
        return sum;
    }
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        return countCandies(ratings, n);
    }
};