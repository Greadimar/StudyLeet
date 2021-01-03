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
    static bool checkSym(TreeNode* aPath, TreeNode* bPath){
        if (aPath == nullptr && bPath == nullptr) return true;
        if ((aPath == nullptr && bPath != nullptr) || (aPath != nullptr && bPath == nullptr)) return false;//if (!n1 || !n2)
        if (aPath->val != bPath->val) return false;
        return (checkSym(aPath->left, bPath->right) && checkSym(aPath->right, bPath->left));

    }
    static bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return checkSym(root->left, root->right);
    }
    //iteration approach - put it in 2 queues. bpath from end, apath from front. than pop it an check
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
