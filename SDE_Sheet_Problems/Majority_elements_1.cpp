class Solution {
public:
    //Moore Voting Algorithm
    int majorityElement(vector<int>& nums){
        int count = 0, element = 0;
        for(int num: nums){
            //First occurrence of the number
            if(count == 0){
                element = num;
            }
            if(num == element){
                count++;
            }
            else{
                count--;
            }
        }
        return element;
    }
};

//Time Complexity: O(n), Space Complexity: O(1)