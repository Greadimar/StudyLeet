#include <QCoreApplication>
#include <queue>
struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    static bool fillLevel(const std::vector<Node*>& previousLevel){
        if (previousLevel.size() == 0) return false;
        std::vector<Node*> curLevel;
        Node* curHeadNode = previousLevel[0];
        Node* curNode = curHeadNode->left;
        curNode->next = curHeadNode->right;
        curNode = curHeadNode->right;
        if (!curNode) return false;
        curLevel.push_back(curHeadNode->left);
        curLevel.push_back(curHeadNode->right);
        for (int i = 1; i < previousLevel.size(); i++){
            curHeadNode = previousLevel[i];
            curNode->next = curHeadNode->left;
            curHeadNode->left->next = curHeadNode->right;
            curNode = curHeadNode->right;
            curLevel.push_back(curHeadNode->left);
            curLevel.push_back(curHeadNode->right);
        }
        return fillLevel(curLevel);
    }

    static Node* connect(Node* root) {
        if (!root) return root;
        fillLevel({root});
        return root;
    }
    Node* connectFast(Node* root) {

         if(root == NULL)
             return root;

         std::queue<Node*> q;
         q.push(root);
         Node* prev = new Node();

         while(!q.empty()) {
             int sz = q.size();

             prev = NULL;
             for(int i = 0; i < sz; i++) {
                 Node* top = q.front();
                 // cout << top->val << " ";
                 if(prev)
                     prev->next = top;
                 if(top->left != NULL)
                     q.push(top->left);
                 if(top->right != NULL)
                     q.push(top->right);
                 prev = top;
                 q.pop();
             }
         }
         return root;
     }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    auto p = Solution::connect(root);
    return a.exec();
}
