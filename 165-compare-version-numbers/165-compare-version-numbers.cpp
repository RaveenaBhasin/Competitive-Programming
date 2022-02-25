class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
    
        string num;

        for(char it : version1)
        {
            if(it == '.')
            {
                v1.push_back(stoi(num));
                num.clear();
            }
            else
                num.push_back(it);
        }

        v1.push_back(stoi(num));
        num.clear();

        for(char it : version2)
        {
            if(it == '.')
            {
                v2.push_back(stoi(num));
                num.clear();
            }
            else
                num.push_back(it);
        }

        v2.push_back(stoi(num));

        int i = 0, n = v1.size(), m = v2.size();

        while(i < min(n, m))
        {
            if(v1[i] < v2[i])
                return -1;

            if(v1[i] > v2[i])
                return 1;

            i++;
        }

        while(i < n)
            if(v1[i++] > 0)
                return 1;

        while(i < m)
            if(v2[i++] > 0)
                return -1;

        return 0;
   
    }
};
