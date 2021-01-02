#include <QCoreApplication>
using namespace std;
#include <stack>
#include <unordered_set>
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
        //need to implement
        std::vector<int> vec;
        std::stack<TreeNode*> stack;
        std::
        stack.push(root);
        TreeNode* curNode;
        while(true){
            if (stack.empty()) break;
            curNode = stack.top();
            if (curNode->left == nullptr && curNode->right == nullptr){
               vec.push_back(curNode->val);
               stack.pop();
               continue;
            }
            else{
                if (curNode->left != nullptr){
                    stack.push(curNode->left);
                    curNode = curNode->left;
                }
                else if (curNode->right != nullptr){
                    stack.push(curNode->right);
                    curNode = curNode->right;
                }
            }

        }
        return vec;
    }
    static void push(std::vector<int> &v, TreeNode* node) {
        if (node != nullptr){

            push(v, node->left);

            push(v, node->right);
            v.push_back(node->val);
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

    return a.exec();
}
