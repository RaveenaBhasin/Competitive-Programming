class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = ((m+n)%2 == 1) ? ((m+n)/2 + 1) : (m+n)/2;
        for(int i = m; i < m+n; i++){
            nums1[i] = nums2[i-m];
        }
        while(k != 0){
            for(int i = 0; i < (m+n-k); i++){
                if(nums1[i] > nums1[i+k]){
                    swap(nums1[i], nums1[i+k]);
                }
            }
            k = (k%2 == 1 && k != 1) ? (k/2 + 1) : (k/2);
        }
    }
};

