#include <QCoreApplication>
// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int answer = 0;
    int maxDepth(TreeNode* root) {              //it's bottom up
        if (!root) {
            return 0;                                 // return 0 for null node
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return std::max(left_depth, right_depth) + 1;	  // return depth of the subtree rooted at root
    }
    void maxTopUp(TreeNode* root, int depth){
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            answer = std::max(answer, depth);
        }
        maxTopUp(root->left, depth + 1);
        maxTopUp(root->right, depth + 1);
    }
    int maxDepthT(TreeNode* root) {              //it's top up
        if (!root) {
            return 0;                                 // return 0 for null node
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return std::max(left_depth, right_depth) + 1;	  // return depth of the subtree rooted at root
    }


};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
