#include <QCoreApplication>
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
    static vector<int> inorderTraversalIt(TreeNode* root) {
        vector<int>res;
        TreeNode* curNode = root;
        if(!curNode){
            return res;
        }
        stack<TreeNode* >st;
        while(true){
            if(curNode != nullptr){
                st.push(curNode);
                curNode=curNode->left;
            }
            else {
                if(st.empty()){
                    break;
                }
                curNode=st.top();
                res.push_back(st.top()->val);
                st.pop();
                curNode=curNode->right;

            }
        }
        return  res;
    }
    static void push(std::vector<int> &v, TreeNode* node) {
        if (node != nullptr){

                push(v, node->left);
             v.push_back(node->val);
                push(v, node->right);
        }
    };
    static vector<int> inorderTraversal(TreeNode* root) {       //faster
        vector<int>vec;
        push(vec, root);
        return  vec;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto n = new TreeNode(1);
    n->left = new TreeNode(2);
    n->left->right = new TreeNode(3);
    auto v = Solution::inorderTraversal(n);
    return a.exec();
}
