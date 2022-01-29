class Solution {
public:
    vector<int>NSL(vector<int>&heights) {
        vector<int>ans;
        stack<pair<int, int>>st;
        int n = heights.size();
        for(int i = 0; i < n; i++) {
            int val = heights[i];
            while(!st.empty() && st.top().first >= val) {
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top().second);
            }
            st.push({val, i});
        }
        return ans;
    }
    
    
    vector<int>NSR(vector<int>&heights) {
        vector<int>ans;
        stack<pair<int, int>>st;
        int n = heights.size();
        for(int i = n-1; i >= 0; i--){
            int val = heights[i];
            while(!st.empty() && st.top().first >= val) {
                st.pop();
            }
            if(st.empty()){
                ans.push_back(n);
            }
            else{
                ans.push_back(st.top().second);
            }
            st.push({val, i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int maxAreaHistogram(vector<int>&heights) {
        vector<int>sl = NSL(heights);   //Nearest smallest to left
        vector<int>sr = NSR(heights);   //Nearest smallest to right
        vector<int>ans;
        int maxArea = INT_MIN, n = heights.size();
        for(int i = 0; i < n; i++){
            ans.push_back(sr[i] - sl[i] - 1);
        }
        for(int i = 0; i < n; i++){
            maxArea = max(maxArea, ans[i] * heights[i]);
        }
        return maxArea;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        return maxAreaHistogram(heights);
    }
};