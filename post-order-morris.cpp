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

void postorder (TreeNode *root) {
  TreeNode* node = new TreeNode(-1);
  TreeNode* pre = NULL, *prev = NULL, *succ = NULL, *temp = NULL;
  node->left = root;
  while (node) {
    if (!node->left) {
      node = node->right;
    } else {
      pre = predecessor(node);
      if (pre->right == NULL) {
        pre->right = node;
        node = node->left;
      } else {
        pre->right = NULL;
        succ = node;
        node = node->left;
        prev = NULL;

        while (node) {
          temp = node->right;
          node->right = prev;
          prev = node;
          node = temp;
        }

        while (prev) {
          cout << prev->val << " ";
          temp = prev->right;
          prev->right = node;
          node = prev;
          prev = temp;
        }
        node = succ;
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
  postorder (root);
  return 0;
}
