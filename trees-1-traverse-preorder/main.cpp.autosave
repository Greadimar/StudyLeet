#include <QCoreApplication>
#include <vector>
#include <stack>
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
    static void push(std::vector<int> &v, TreeNode* node) {
        if (node != nullptr){
            v.push_back(node->val);
            if (node->left != nullptr){
                push(v, node->left);
            }
            if (node->right != nullptr){
                push(v, node->right);
            }
        }
    };
    static vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> v;
        push(v, root);
        return v;
    }
    static vector<int> preorderTraversalBest(TreeNode* root) {
        vector<int>res;
         if(!root)
         {
             return res;
         }
         stack<TreeNode* >st;
         while(true)
         {
             if(root!=NULL)
             {
                 st.push(root);
                 res.push_back(st.top()->val);
                 root=root->left;
             }
             else
             {
                 if(st.empty())
                 {
                     break;
                 }
                 root=st.top();
                 st.pop();
                 root=root->right;
             }
         }
         return  res;

    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto n = new TreeNode(3);
    n->right = new TreeNode(2);
    n->left = new TreeNode(1);
    auto v = Solution::preorderTraversal(n);
    return a.exec();
}
