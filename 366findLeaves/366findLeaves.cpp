class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        dfs(root, nullptr);
        queue<TreeNode*> q;
        vector<int> tmp;
        for (auto i : outdegree)
        {
            if (i.second == 0)
            {
                q.push(i.first);
                tmp.push_back(i.first->val);
            }
        }
        ans.push_back(tmp);
        while (!q.empty())
        {
            tmp.clear();
            int qsize = q.size();
            while (qsize--)
            {
                auto node = q.front();
                q.pop();
                TreeNode* parent = childP[node];
                if (parent)
                {
                    outdegree[parent]--;
                    if (outdegree[parent] == 0)
                    {
                        tmp.push_back(parent->val);
                        q.push(parent);
                    }
                }
            }
            if (!tmp.empty()) ans.push_back(tmp);
        }
        return ans;
    }
    void dfs(TreeNode* root, TreeNode* parent)
    {
        if (!root) return;
        childP[root] = parent;
        outdegree[root] = 0;
        if (root->left)
        {
            outdegree[root]++;
            dfs(root->left, root);
        }
        if (root->right)
        {
            outdegree[root]++;
            dfs(root->right, root);
        }
    }
private:
    unordered_map<TreeNode*, int> outdegree;
    unordered_map<TreeNode*, TreeNode*> childP;
};