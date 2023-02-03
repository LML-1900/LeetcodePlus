class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<vector<int>> graph(n + 1);
        vector<unordered_set<int>> visited(n + 1);
        vector<int> indegree(n + 1, 0);
        // 根据序列建立有向图，每个序列的相邻两个数字代表图中节点的先后顺序
        // 利用set排除重边，用indegree记录每个节点的入度
        for (auto seq : sequences)
        {
            for (int i = 0; i < seq.size() - 1; i++)
            {
                int fst = seq[i], sec = seq[i + 1];
                if (visited[fst].count(sec) == 0)
                {
                    visited[fst].insert(sec);
                    graph[fst].push_back(sec);
                    indegree[sec]++;
                }
            }
        }
        // 拓扑排序
        queue<int> q;
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }
        while (!q.empty())
        {
            int qsize = q.size();
            // 如果队列大小大于1，说明该拓扑排序不唯一，不存在唯一超序列
            if (qsize > 1) return false;
            int id = q.front();
            q.pop();
            for (auto i : graph[id])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    ans.push_back(i);
                    q.push(i);
                }
            }
        }
        // 如果nums与拓扑排序结果不符合，说明其不是最短超序列
        if (ans.size() != n) return false;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] != nums[i]) return false;
        }
        return true;
    }
};
