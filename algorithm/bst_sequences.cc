#include <iostream>
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

    int BSTNodes(TreeNode* root) {
        if (!root) return 0;
        return BSTNodes(root->left) + BSTNodes(root->right) + 1;
    }

    void backtrack(vector<TreeNode*> Q,
                   vector<vector<int>>& result,
                   vector<int>& tmp,
                   int n) {
        if (tmp.size() == n) {
            result.push_back(tmp);
            return;
        }

        for (int i = 0; i < Q.size(); i++) {
            TreeNode* t = Q[i];
            tmp.push_back(t->val);

            std::vector<TreeNode*> nextQ;
            for (int j = 0; j < Q.size(); j++) {
                if (j != i) {
                    nextQ.push_back(Q[j]);
                }
            }
            if (t->left) {
                nextQ.push_back(t->left);
            }
            if (t->right) {
                nextQ.push_back(t->right);
            }

            backtrack(nextQ, result, tmp, n);
            tmp.pop_back();
        }

    }

    vector<vector<int>> BSTSequences(TreeNode* root) {
        vector<vector<int>> result;

        if (!root) return result;

        int n = BSTNodes(root);
        std::cout  << "n = " << n << std::endl;
        vector<int> tmp;
        tmp.push_back(root->val);
        std::vector<TreeNode*> Q;
        if (root->left) {
            Q.push_back(root->left);
        }
        if (root->right) {
            Q.push_back(root->right);
        }
        backtrack(Q, result, tmp, n);
        return result;
    }

int main(int argc, char* argv[]) {
    TreeNode n1(1);
    TreeNode n4(4);
    TreeNode n3(3, &n1, &n4);
    TreeNode n6(6);
    TreeNode n9(9);
    TreeNode n8(8, &n6, &n9);
    TreeNode n5(5, &n3, &n8);
    std::vector<vector<int>> result = BSTSequences(&n5);

    for (auto j : result) {
		std::cout << "[";
		for (auto i : j) {
        	std::cout << i << " ";
		}
		std::cout << "]\n";
    }
    std::cout << std::endl;

    return 0;
}
