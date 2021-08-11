#include <bits/stdc++.h>

using namespace std;

class TreeNode {
  public:
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode(int val) {
    this->val = val;
    left = NULL;
    right = NULL;
  }
};

/* finding inorder-predecessor
   which means the largest element in the left subtree.
*/
TreeNode* predecessor(TreeNode *root) {
  TreeNode* node = root->left;
  while (node->right != NULL and node->right != root) {
    node = node->right;
  }
  return node;
}

void preorder (TreeNode *root) {
  TreeNode* node = root;
  while (node) {
    if (!node->left) {
      cout << node->val << " ";
      node = node->right;
    } else {
      auto pre = predecessor(node);
      if (pre->right == NULL) {
        cout << node->val << " ";
        pre->right = node;
        node = node->left;
      } else {
        pre->right = NULL;
        node = node->right;
      }
    }
  }
}

int main() {
  TreeNode* root = new TreeNode(10);
  root->left = new TreeNode(4);
  root->right = new TreeNode(20);
  root->left->left = new TreeNode(2);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(40);
  preorder (root);
  return 0;
}
