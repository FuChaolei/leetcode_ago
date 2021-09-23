/*
 * @lc app=leetcode.cn id=535 lang=cpp
 *
 * [535] TinyURL 的加密与解密
 *
 * https://leetcode-cn.com/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (84.00%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    14.7K
 * Total Submissions: 17.5K
 * Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
 *
 * TinyURL是一种URL简化服务， 比如：当你输入一个URL https://leetcode.com/problems/design-tinyurl
 * 时，它将返回一个简化的URL http://tinyurl.com/4e9iAk.
 * 
 * 要求：设计一个 TinyURL 的加密 encode 和解密 decode
 * 的方法。你的加密和解密算法如何设计和运作是没有限制的，你只需要保证一个URL可以被加密成一个TinyURL，并且这个TinyURL可以用解密方法恢复成原本的URL。
 * 
 */

// @lc code=start
class Solution
{
public:
    int n = 0;
    unordered_map<int, string> mp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        mp[n] = longUrl;
        return "http://" + to_string(n++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        int key = stol(shortUrl.substr(7, shortUrl.size() - 7));
        return mp[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @lc code=end
