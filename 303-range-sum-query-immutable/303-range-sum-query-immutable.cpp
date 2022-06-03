class NumArray {
    vector<int>res;
public:
    NumArray(vector<int>& nums) {
        res.push_back(0);
        for(int it : nums){
            res.push_back(res.back() + it);
        }
    }
    
    int sumRange(int left, int right) {
        return res[right+1] - res[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */