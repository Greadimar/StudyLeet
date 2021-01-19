#include <QCoreApplication>
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

    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !q || !p) return nullptr;
         if (root == p || root == q) return root;
        auto leftNode = lowestCommonAncestor(root->left, p, q);
        auto rightNode = lowestCommonAncestor(root->right, p, q);
        if (leftNode && rightNode) return root;
        if (!leftNode && !rightNode) return nullptr;
        if (leftNode) return leftNode;
        return rightNode;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
        TreeNode* root = new TreeNode(3);
        root->left = new TreeNode(5);
        root->left->left = new TreeNode(6);
        root->left->right = new TreeNode(2);
        root->left->right->left = new TreeNode(7);
        root->left->right->right = new TreeNode(4);

        root->right = new TreeNode(1);
        root->right->left = new TreeNode(0);
        root->right->right = new TreeNode(8);
//    TreeNode* root = new TreeNode(1);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(3);
    auto p = Solution::lowestCommonAncestor(root, root->right, root->left);
    return a.exec();
}
