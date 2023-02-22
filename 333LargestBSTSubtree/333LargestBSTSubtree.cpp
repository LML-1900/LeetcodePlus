 //自己想的枚举法，时间复杂度O(n^2),运行时间16ms
 class Solution {
 public:
     int largestBSTSubtree(TreeNode* root) {
         if (!root) return 0;
         if (isBSTTree(root, INT_MIN, INT_MAX)) return getNodeNum(root);
         return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
     }
 private:
     unordered_map<TreeNode*, int> nodeNum;
     int ans = 0;
     int getNodeNum(TreeNode* root)
     {
         if (!root) return 0;
         if (nodeNum.find(root) != nodeNum.end()) return nodeNum[root];
         nodeNum[root] = getNodeNum(root->left) + getNodeNum(root->right) + 1;
         return nodeNum[root];
     }
     bool isBSTTree(TreeNode* root, int lower, int upper)
     {
         if (!root) return true;
         if (root->val <= lower || root->val >= upper) return false;
         if (isBSTTree(root->left, lower, root->val) && isBSTTree(root->right, root->val, upper)) return true;
         return false;
     }
 };

 // 复用子树的二叉搜索信息，理论应该是O(n),但是运行时间24ms，反而更慢了
 class Solution {
 public:
     int largestBSTSubtree(TreeNode* root) {
         if (!root) return 0;
         if (isBSTTree(root)) return getNodeNum(root);
         return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
     }
 private:
     unordered_map<TreeNode*, int> nodeNum;
     unordered_map<TreeNode*, bool> isBST;
     unordered_map<TreeNode*, pair<int, int>> minmax;
     int ans = 0;
     int getNodeNum(TreeNode* root)
     {
         if (!root) return 0;
         if (nodeNum.find(root) != nodeNum.end()) return nodeNum[root];
         nodeNum[root] = getNodeNum(root->left) + getNodeNum(root->right) + 1;
         return nodeNum[root];
     }
     pair<int, int> getMinMax(TreeNode* root)
     {
         if (!root) return { INT_MAX, INT_MIN };
         if (minmax.find(root) != minmax.end()) return minmax[root];
         auto p1 = getMinMax(root->left), p2 = getMinMax(root->right);
         int minval = min(root->val, min(p1.first, p2.first));
         int maxval = max(root->val, max(p1.second, p2.second));
         return minmax[root] = { minval, maxval };
     }
     bool isBSTTree(TreeNode* root)
     {
         if (!root) return true;
         if (isBST.find(root) != isBST.end()) return isBST[root];
         bool left = false, right = false;
         if (isBSTTree(root->left) && getMinMax(root->left).second < root->val) left = true;
         if (isBSTTree(root->right) && getMinMax(root->right).first > root->val) right = true;
         return isBST[root] = left && right;
     }
 };