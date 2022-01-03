class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        unordered_map<int,int> count;//count the number of people who trust ith person
        unordered_map<int,int> check;//count the number of people whom ith person trusts
        for(int i=0;i<trust.size();i++)
        {
            count[trust[i][1]]++;
            check[trust[i][0]]++;
        }
        for(int i=1;i<=N;i++)
        {
            if(count[i]==N-1 && check[i]==0)
                return i;
        }
        return -1;
    }
};
