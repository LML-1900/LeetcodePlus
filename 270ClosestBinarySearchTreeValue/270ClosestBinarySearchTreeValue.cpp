 class Solution {
 public:
     int closestValue(TreeNode* root, double target) {
         diff = 1e10;
         close(root, target);
         return ans;
     }
     void close(TreeNode* root, double target)
     {
         if (!root) return;
         if (diff > fabs(root->val - target))
         {
             diff = fabs(root->val - target);
             ans = root->val;
         }
         if (target < root->val) close(root->left, target);
         else if (target > root->val) close(root->right, target);
     }
 private:
     int ans;
     double diff;
 };