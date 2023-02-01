#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& maze, vector<int> start, vector<int> end, unordered_set<int>& s)
    {
        if (start[0] == end[0] && start[1] == end[1]) return true;
        int m = maze.size(), n = maze[0].size();
        // 记录所有停下过的点
        s.insert(start[0] * n + start[1]);
        vector<int> idir = { -1, 0, 1, 0 }, jdir = { 0, 1, 0, -1 };
        bool ans;
        for (int k = 0; k < 4; k++)
        {
            int i = start[0] + idir[k], j = start[1] + jdir[k];
            if (i >= 0 && i < m && j >= 0 && j < n && maze[i][j] == 0)
            {
                while (i >= 0 && i < m && j >= 0 && j < n && maze[i][j] == 0)
                {
                    i += idir[k];
                    j += jdir[k];
                }
                i -= idir[k], j -= jdir[k];
                if (s.count(i * n + j) == 0)
                {
                    ans = dfs(maze, { i, j }, end, s);
                    if (ans) return true;
                }
            }
        }
        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        unordered_set<int> s;
        int n = maze[0].size();
        s.insert(start[0] * n + start[1]);
        return dfs(maze, start, destination, s);
    }
};

// bfs做法
bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    unordered_set<int> s;
    int n = maze[0].size(), m = maze.size();
    queue<vector<int>> q;
    q.push(start);
    s.insert(start[0] * n + start[1]);
    vector<int> idir = { -1, 0, 1, 0 }, jdir = { 0, 1, 0, -1 };
    while (!q.empty())
    {
        auto pos = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int i = pos[0] + idir[k], j = pos[1] + jdir[k];
            if (i >= 0 && i < m && j >= 0 && j < n && maze[i][j] == 0)
            {
                while (i >= 0 && i < m && j >= 0 && j < n && maze[i][j] == 0)
                {
                    i += idir[k];
                    j += jdir[k];
                }
                i -= idir[k], j -= jdir[k];
                if (s.count(i * n + j) == 0)
                {
                    if (i == destination[0] && j == destination[1]) return true;
                    s.insert(i * n + j);
                    q.push({ i, j });
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> maze = { {0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1} ,{0,0,0,0,0} };
    vector<int> start = { 0, 4 }, end = { 1, 2 };
    Solution s;
    cout << hasPath(maze, start, end);
    return 0;
}