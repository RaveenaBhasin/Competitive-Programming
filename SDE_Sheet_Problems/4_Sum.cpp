class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        if(nums.size()==0){
            return res;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int remTarget = target - nums[i] - nums[j];
                int left = j+1;
                int right = n-1;
                while(left < right){
                    if(nums[left] + nums[right] < remTarget){
                        left++;
                    }
                    else if(nums[left] + nums[right] > remTarget){
                        right--;
                    }
                    else{
                        vector<int>quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[left];
                        quad[3] = nums[right];
                        res.push_back(quad);
                        //Avoiding duplicates
                        while(left < right && nums[left] == quad[2]){
                            left++;
                        }
                        
                        while(left < right && nums[right] == quad[3]){
                            right--;
                        }
                    }
                }
                //Moving to the end of duplicates not crossing it
                while(j + 1 < n && nums[j+1] == nums[j]){
                    j++;
                }
                while(i + 1 < n && nums[i+1] == nums[i]){
                    i++;
                }
            }
        }
        return res;
    }
};

//T.C : O(n^2) S.C : O(n^2)