class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n= nums.size();
        if(n==0 || k<=0){
            return;
        }
        vector<int>v(n);
        for(int i=0;i<n;i++){
            v[i]=nums[i];
        }
        for(int i=0;i<n;i++){
            nums[(i+k)%n] = v[i];
        }
    }
};
