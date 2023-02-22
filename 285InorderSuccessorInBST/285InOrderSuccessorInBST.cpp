 class Solution {
 public:
     TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
         inorder(root, p);
         return ans;
     }
     void inorder(TreeNode* root, TreeNode* p)
     {
         if (root->left) inorder(root->left, p);
         if (found)
         {
             ans = root;
             found = false;
             return;
         }
         if (root == p) found = true;
         if (root->right) inorder(root->right, p);
     }
 private:
     bool found = false;
     TreeNode* ans = nullptr;
 };