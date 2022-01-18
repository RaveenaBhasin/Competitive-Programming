class Solution {
public:
    int trap(vector<int>& height) {
        //Indices to traverse an array
        int n = height.size();
        int left = 0, right = n-1;
        //To store left max and right max
        int l_max = 0, r_max = 0;
        //To store the total amount of rain water trapped
        int result = 0;
        while(left <= right){
            if(height[left] < height[right]){
                if(height[left] > l_max){
                    //Update left maximum
                    l_max = height[left];
                }
                else{
                    result += l_max - height[left];
                }
                left++;
            }
            else{
                if(height[right] > r_max){
                    //Update right maximum
                    r_max = height[right];
                }
                else{
                    result += r_max - height[right];
                }
                right--;
            }
        }
        return result;
    }
};