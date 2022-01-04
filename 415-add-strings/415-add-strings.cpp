class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int n1 = num1.size() - 1, n2 = num2.size() - 1, carry = 0;
        while (n1 >= 0 || n2 >= 0 || carry > 0) {
            if (n1 >= 0) {
                carry += num1[n1] - '0';
                n1 -= 1;
            }
            if (n2 >= 0) {
                carry += num2[n2] - '0';
                n2 -= 1;
            }
            ans += char(carry % 10 + '0');
            carry /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};