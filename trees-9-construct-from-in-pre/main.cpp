#include <QCoreApplication>
using namespace std;
#include <unordered_map>
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

    static TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        std::unordered_map<int, int> map;
        // map of inorder value positions;
        for (int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }
        std::function<TreeNode*(int, int, int, int)> fillNode;
        fillNode = [&](int pBegin, int pEnd, int iBegin, int iEnd) -> TreeNode*{
            if (pBegin >= pEnd || iBegin >= iEnd ) return nullptr;
            int headVal = preorder[pBegin];
            auto node = new TreeNode(headVal);
            int posInorder = map[headVal];
            int shift = posInorder - iBegin + 1; // count of elements to left;
            node->left = fillNode(pBegin + 1, pEnd, iBegin, posInorder);
            node->right = fillNode(pBegin + shift, pEnd, posInorder + 1, iEnd);
            return node;
        };
        return fillNode(0, preorder.size(), 0, inorder.size());

    }
};
class SolutionFastest {
public:
    TreeNode* build(bool hasEnd, int end, vector<int>& pre, vector<int>& in, int& i, int& j) {
        if(j >= in.size() || (hasEnd && in[j] == end)) {
            return nullptr;
        }

        TreeNode * curr = new TreeNode(pre[i]);
        // preorder pops
        i++;

        curr->left = build(true, curr->val, pre, in, i, j);
        // inorder pops
        j++;

        curr->right = build(hasEnd, end, pre, in, i, j);
        return curr;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) {
            return nullptr;
        }
        int j = 0, i = 0;
        return build(false, 0, preorder, inorder, i, j);
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::vector<int> io{9,3,15,20,7};
    std::vector<int> po{3,9,20,15,7};
    auto p = Solution::buildTree(po, io);
    return a.exec();
}
