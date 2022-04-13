class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0, left = 0, right = n-1, down = n-1, cnt = 1;
        vector<vector<int>>ans(n, vector<int>(n));
        while(top <= down && left <= right){
            for(int i = left; i <= right; i++) {
                ans[top][i] = cnt++;
            }
            top++;
            for(int i = top; i <= down; i++){
                ans[i][right] = cnt++;
            }
            right--;
            for(int i = right; i >= left; i--){
                ans[down][i] = cnt++;
            }
            down--;
            for(int i = down; i >= top; i--){
                ans[i][left] = cnt++;
            }
            left++;
        }
        return ans;
    }
};