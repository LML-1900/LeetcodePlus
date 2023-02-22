 // 抄了别人的正确题解
 class Solution {
 public:
     NodeCopy* copyRandomBinaryTree(Node* root) {
         if (!root) return nullptr;
         NodeCopy* rootCopy;
         if (mp.find(root) != mp.end()) return mp[root];
         else
         {
             rootCopy = new NodeCopy(root->val);
             mp[root] = rootCopy;
         }
         rootCopy->left = copyRandomBinaryTree(root->left);
         rootCopy->right = copyRandomBinaryTree(root->right);
         rootCopy->random = copyRandomBinaryTree(root->random);
         return rootCopy;
     }
 private:
     map<Node*, NodeCopy*> mp;
 };

// 自己写的不知道错在哪里
// 一旦遇到random是还没建立的节点，最终返回结果就会把这个random变成null
 class Solution {
 public:
     NodeCopy* copyRandomBinaryTree(Node* root) {
         if (!root) return nullptr;
         NodeCopy* rootCopy;
         if (mp.find(root) != mp.end()) rootCopy = mp[root];
         else
         {
             rootCopy = new NodeCopy(root->val);
             mp[root] = rootCopy;
         }
         if (root->random)
         {
             if (mp.find(root->random) != mp.end())
             {
                 rootCopy->random = mp[root->random];
             }
             else
             {
                 NodeCopy* randomCopy = new NodeCopy(root->random->val);
                 mp[root->random] = randomCopy;
             }
         }
         rootCopy->left = copyRandomBinaryTree(root->left);
         rootCopy->right = copyRandomBinaryTree(root->right);
         return rootCopy;
     }
 private:
     map<Node*, NodeCopy*> mp;
 };