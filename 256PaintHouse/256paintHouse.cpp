class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<array<int, 3>> dp(n);
        for (int i = 0; i < 3; i++) dp[0][i] = costs[0][i];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j + 2]) + costs[i][j];
                }
                else if (j == 1)
                {
                    dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j - 1]) + costs[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j - 2]) + costs[i][j];
                }
                // 三个状态合成一个!
                //dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + costs[i][j];
            }
        }
        return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    }
};