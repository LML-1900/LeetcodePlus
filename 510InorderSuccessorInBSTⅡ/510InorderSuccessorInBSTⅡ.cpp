 // 自己写的，24ms，11.4MB
 class Solution {
 public:
     Node* inorderSuccessor(Node* node) {
         if (node->right) return inorderTraverse(node->right);
         else if (node->parent) return reverseTraverse(node->parent, node);
         return nullptr;
     }
     Node* reverseTraverse(Node* node, Node* lastNode)
     {
         if (node->right == lastNode)
         {
             if (node->parent)
                 return reverseTraverse(node->parent, node);
             else return nullptr;
         }
         else return node;
     }
     Node* inorderTraverse(Node* node)
     {
         if (node->left) return inorderTraverse(node->left);
         return node;
     }
 };

 // 参考题解的，20ms，11.2MB
 class Solution {
 public:
     Node* inorderSuccessor(Node* node) {
         if (node->right)
         {
             node = node->right;
             while (node->left)
             {
                 node = node->left;
             }
             return node;
         }
         else
         {
             while (node->parent && node->parent->right == node)
             {
                 node = node->parent;
             }
             return node->parent;
         }
     }
 };