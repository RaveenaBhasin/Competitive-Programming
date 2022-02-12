class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        bool present = false;
        for (auto word : wordList)
        {
            if (!endWord.compare(word))
                present = true;
            st.insert(word);
        }
        if (!present)
            return 0;
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        while (!q.empty())
        {
            depth += 1;
            int len = q.size();
            while(len--)
            {
                string curr = q.front();
                q.pop();
                for(int i = 0; i < curr.length(); i++)
                {
                    string temp = curr;
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;
                        if (!curr.compare(temp))
                            continue;
                        if (!temp.compare(endWord))
                            return depth + 1;
                        if (st.find(temp) != st.end())
                            q.push(temp), st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};