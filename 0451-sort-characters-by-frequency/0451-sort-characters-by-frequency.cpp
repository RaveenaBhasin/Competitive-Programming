class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m; // Create a hashmap to store the count of each character in the string
        for (auto c : s) {
            m[c]++; // Increment the count of the character c in the hashmap
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            // Sort the string in decreasing order of the count of each character in the string.
            // If the count is same, then sort the characters in increasing order.
            return m[a] > m[b] || (m[a] == m[b] && a < b);
        });
        return s;
    }
};