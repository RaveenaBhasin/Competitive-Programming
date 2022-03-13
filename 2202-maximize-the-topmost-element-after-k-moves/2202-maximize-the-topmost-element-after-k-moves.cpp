class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int m=INT_MIN;
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            st.push(nums[i]);
        }
        if(nums.size()==0){
            return -1;
        }
        if(k==0){
            return nums[0];
        }
        if(nums.size()==1 and k%2!=0){
            return -1;
        }
        int out=0;
        while(k>0 and !st.empty()){
            if(k==1){
                    st.pop();
                    if(!st.empty()){
                        m=max(m,st.top());
                    }
                    k--;
                }
            else if(!st.empty()){
                m=max(m,st.top());
                st.pop();
                k--;
            }
        }
        if(!st.empty()){
            m=max(m,st.top());
        }
        return m;
    }
};