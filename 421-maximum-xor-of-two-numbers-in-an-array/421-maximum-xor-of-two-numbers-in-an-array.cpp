class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int max_xor = 0;
        int mask = 0;

        for (int i = 31; i >= 0; i--) {
            mask = mask | (1 << i);
            unordered_set<int> prefix_set;
            for (int num : nums) {
                prefix_set.insert(num & mask);
            }

            int tmp = max_xor | (1 << i);
            for (int prefix : prefix_set) {
                if (prefix_set.find(tmp ^ prefix) != prefix_set.end()) {
                    max_xor = tmp;
                    break;
                }
            }
        }

        return max_xor;
    }
};