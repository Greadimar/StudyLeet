#include <QCoreApplication>
#include <queue>
using namespace std;
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> result;
        if (!root) return result;
        std::queue<TreeNode*> curQu;
        TreeNode* curNode = root;
        curQu.push(curNode);
        while(!curQu.empty()){
            std::vector<int>level;
            //filling queue;
            int size = curQu.size();
            for(int i = 0; i < size; i++){
                TreeNode* top = curQu.front();
                level.push_back(top->val);
                curQu.pop();
                if (top->left != nullptr) curQu.push(top->left);
                if (top->right != nullptr) curQu.push(top->right);
            }
            result.push_back(level);
        }
        return result;
    }

    vector<vector<int>> res ;
    void helper (TreeNode* root , int level) {
        if (!root)
            return ;

        if (res.size() == level) res.push_back(vector<int> ()) ; //creating a new row at each level

        res[level].push_back(root->val) ; //pushing values of node at each level

        helper(root->left , level + 1) ;  //incrementing level as we go down
        helper(root->right , level + 1) ;
    }
    vector<vector<int>> levelOrderFast(TreeNode* root) {
        helper (root , 0) ;
        return res ;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
