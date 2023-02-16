// dp法，dp[i][j]表示以第i个字符和第j个字符结尾的子串重复的最长长度，注意j一定要大于i，不然就会找到同一个子串
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int len = s.size();
        vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
        int ans = 0;
        for (int i = 1; i <= len; i++)
        {
            // j = i + 1!非常关键！
            for (int j = i + 1; j <= len; j++)
            {
                if (s[i - 1] == s[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans; 
    }
};

// 哈希+二分查找
class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        // 预处理，求出每个字符子串哈希值
        p = vector<unsigned long long>(n + 1, 1);
        strHash = vector<unsigned long long>(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            p[i] = p[i - 1] * P;
            strHash[i] = strHash[i - 1] * P + s[i - 1];
        }
        // 二分查找最长重复子串，如果长度为l有重复子串，长度小于l的一定也有重复子串
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2 + 1;
            if (hasRepeatedStr(mid, n)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
private:
    vector<unsigned long long> p, strHash;
    const int P = 131;
    // 获取子串哈希值
    unsigned long long getHash(int l, int r)
    {
        return strHash[r] - strHash[l - 1] * p[r - l + 1];
    }
    // 判断长度为len的子串是否重复
    bool hasRepeatedStr(int len, int n)
    {
        // 用哈希表记录所有长度为len的子串的个数，个数大于等于2立即返回true
        unordered_map<unsigned long long, int> hashmap;
        for (int i = 1; i <= n - len + 1; i++)
        {
            unsigned long long hashval = getHash(i, i + len - 1);
            hashmap[hashval]++;
            if (hashmap[hashval] >= 2) return true;
        }
        return false;
    }
};