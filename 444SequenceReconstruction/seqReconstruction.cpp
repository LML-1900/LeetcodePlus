class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<vector<int>> graph(n + 1);
        vector<unordered_set<int>> visited(n + 1);
        vector<int> indegree(n + 1, 0);
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
        if (ans.size() != n) return false;
        for (int i = 0; i < n; i++)
        {
            if (ans[i] != nums[i]) return false;
        }
        return true;
    }
};
