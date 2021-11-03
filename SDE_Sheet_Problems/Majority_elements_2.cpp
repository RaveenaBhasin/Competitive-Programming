class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {  
        vector<int>v;
        int num1 = -1, num2 = -2, count1 = 0, count2 = 0;
        for(int ele:nums){
            if(ele == num1){
                count1++;
            }
            else if(ele == num2){
                count2++;
            }
            else if(count1 == 0){
                num1 = ele;
                count1 = 1;
            }
            else if(count2 == 0){
                num2 = ele;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(auto ele:nums){
            if(ele == num1){
                count1++;
            }
            if(ele == num2){
                count2++;
            }
        }
        if(count1>nums.size()/3){
            v.push_back(num1);
        }
        if(count2>nums.size()/3){
            v.push_back(num2);
        }
        return v;
    }
};

//Time Complexity: O(n), Space Complexity: O(1)