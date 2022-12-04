class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int res=0;
        long long int s=0,m=INT_MAX;
        long long int n=nums.size();
        for(int i=0;i<n;i++){
            s+=nums[i];
        }
        long long int sum=0;
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            long long int cur = abs(sum/(i+1)-(s-sum)/(n-i-1));
            if(cur < m){
                m = cur;
                res = i;
            }
        }
        if(m > s/nums.size()){
            return nums.size()-1;
        }
        else{
            return res;
        }
    }
};