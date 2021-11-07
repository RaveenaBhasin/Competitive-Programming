class Solution {
public:
    // Gap method : We basically traverse array with gap between elements, we swap elements if the first element in gap is greater than second element.
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Gap is always a ceil value i.e. sum of number of elements in both array divided by 2.
        int gap = ((m+n)%2==1) ? ((m+n)/2 + 1) : (m+n)/2;
        for(int i = m; i<m+n; i++){
            nums1[i] = nums2[i-m];
        }
        while(gap!=0){
            for(int i = 0; i<(m+n-gap); i++){
                if(nums1[i]>nums1[i+gap]){
                    swap(nums1[i], nums1[i+gap]);
                }
            }
            //If gap>1 and then take ceil value
            gap = (gap%2==1 && gap!=1) ? (gap/2+1) : (gap/2);
        }
    }
};

//T.C : O(nlogn)   S.C : O(1)