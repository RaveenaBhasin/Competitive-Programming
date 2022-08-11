class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map < char, int > mp;
        for (int i = 0; i < m; i++) mp[t[i]]++;

        int count = mp.size();
        int i = 0, j = 0, ans = INT_MAX;
        string res = "";
        while (j < n) {
            if (mp.find(s[j]) != mp.end()) {
              mp[s[j]]--;
              if (mp[s[j]] == 0)
                count--;
            }

            if (count > 0) j++;
            else if (count == 0) {
              if (j - i + 1 < ans) {
                ans = j - i + 1;
                res = s.substr(i, ans);
              }

              while (count == 0) {
                if (mp.find(s[i]) == mp.end()) {
                  i++;
                  if (j - i + 1 < ans) {
                    ans = j - i + 1;
                    res = s.substr(i, ans);
                  }
                } else {
                  mp[s[i]]++;
                  if (mp[s[i]] > 0) {
                    i++;
                    count++;
                  } else {
                    i++;
                    if (j - i + 1 < ans) {
                      ans = j - i + 1;
                      res = s.substr(i, ans);
                    }
                  }
                }
              }
              j++;
            }
          }

      return res;


    }
};