#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

void postorderIterately(TreeNode* root, vector<int>& result) {
    if (!root) return;
    std::stack<std::pair<TreeNode*, int>> s;
    TreeNode* t = root;
    while (t) {
        int count = 0;
        if (t->right) {
            count++;
        }
        s.push(std::make_pair(t, count));
        t = t->left;
    }

    while (!s.empty()) {
        auto& x = s.top();
        if (x.second == 0) {
            result.push_back(x.first->val);
            s.pop();
            continue;
        } else if (x.second > 0) {
            x.second--;
        }

        TreeNode* t = x.first->right;
        while (t) {
            int count = 0;
            if (t->right) {
                count++;
            }
            s.push(std::make_pair(t, count));
            t = t->left;
        }
    }
}

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        // postorderRecursively(root, result);
        postorderIterately(root, result);
        return result;
    }

int main(int argc, char* argv[]) {
    TreeNode a(2);
    TreeNode b(3);
    TreeNode root(1, &a, &b);
    std::vector<int> result = postorderTraversal(&root);

    for (auto i : result) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}
