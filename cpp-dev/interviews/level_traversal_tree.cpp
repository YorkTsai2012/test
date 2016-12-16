/**
 * Definition of TreeNode:
*/

#include <vector>
#include <queue>
using namespace std;

class TreeNode {
  public:
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
};
 
 
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // write your code here
        vector<vector<int> > order;
        if (!root) {
            return order;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            int levelSize = Q.size();
            vector<int> levelOrder;
            for (int i = 0; i < levelSize; i++) {
                TreeNode* cur  = Q.front();
                levelOrder.push_back(cur->val);
                Q.pop();
                if (cur->left) {
                    Q.push(cur->left);
                }
                if (cur->right) {
                    Q.push(cur->right);
                }
            }
            order.push_back(levelOrder);
        }
        return order;
    }
};

