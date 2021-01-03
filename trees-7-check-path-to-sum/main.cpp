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
    bool downPath(TreeNode* n, int&& curSum, const int& sum){
        if (!n->left && !n->right) return curSum + n->val == sum;
        bool pathFound = false;
        if (n->left){
            pathFound = downPath(n->left, curSum + n->val, sum);
        }
        if (!pathFound && n->right){
            pathFound = downPath(n->right, curSum + n->val, sum);
        }
        return pathFound;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return  false;
        return downPath(root, 0, sum);
    }

    bool hasPathSumBest(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL && sum - root->val == 0) return 1;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};


class SolutionDecent {
public:
    bool ans;
    int sm;

    void solve(TreeNode* r, int curr){
        if(r == NULL)return;
        if(r->left == NULL && r->right == NULL){
            curr += r->val;
            if(sm == curr)ans = true;
            return;
        }
        solve(r->left, curr + r->val);
        solve(r->right, curr + r->val);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        ans = false;
        sm = sum;
        solve(root, 0);
        return ans;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    return a.exec();
}
