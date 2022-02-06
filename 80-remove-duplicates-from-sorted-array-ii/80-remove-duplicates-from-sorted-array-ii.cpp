class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, len=0, n=nums.size();
        while(i<n){
            int cnt=1;
            while(i+1<n && nums[i]==nums[i+1]){
               i++;
               if(cnt<2)cnt++; 
            }
            if(cnt==1)nums[len]=nums[i];
            if(cnt==2)nums[len]=nums[len+1]=nums[i];
            len+=cnt;
            i++;
        }
        return len;
    }
};