class Solution {
public:

    // Encodes a URL to a shortened URL.
    map<string, string>mp;
    int count;
    
    string encode(string longUrl) {
        count++;
        string baseUrl = "http://tinyurl.com/";
        string code = to_string(count);
        baseUrl += code;
        mp[baseUrl] = longUrl;
        return baseUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));