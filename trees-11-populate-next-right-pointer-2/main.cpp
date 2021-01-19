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
    static bool fillLevel (std::queue<Node*>& previousLevel){
        if (previousLevel.size() == 0) return false;
        Node* curHeadNode = previousLevel.front();
        Node* curNode = nullptr;
        previousLevel.pop();
         int sz = previousLevel.size();

         while (!curHeadNode->left && !curHeadNode->right) {
                          if (sz == 0) return false;
              curHeadNode = previousLevel.front();
             previousLevel.pop();
             sz = previousLevel.size();

         }

        if (curHeadNode->left){
            curNode = curHeadNode->left;
            previousLevel.push(curNode);
        }
        if (curHeadNode->right){
            if (curNode) curNode->next = curHeadNode->right;
            curNode = curHeadNode->right;
            previousLevel.push(curNode);
        }

        for (int i = 0; i < sz; i++){
            curHeadNode = previousLevel.front();
            previousLevel.pop();
            if (curHeadNode->left){
                curNode->next = curHeadNode->left;
                curNode = curHeadNode->left;
                previousLevel.push(curNode);
            }
            if (curHeadNode->right){
                curNode->next = curHeadNode->right;
                curNode = curHeadNode->right;
                previousLevel.push(curNode);
            }
        }
        return fillLevel(previousLevel);
    }

    static Node* connect(Node* root) {
        if (!root) return root;
        std::queue<Node*> qu;
        qu.push(root);
        fillLevel(qu);
        return root;
    }

};

class SolutionFast {
public:
    void processChild(Node *node, Node *&child, Node *&firstChild){
        if(node){
            if(firstChild){
                child->next = node;
                child = node;
            }
            else{
                firstChild = node;
                child = node;
            }
        }
    }

    Node* connect(Node* root) {
        Node *firstChild = root;

        while(firstChild){
            Node *parent = firstChild;
            firstChild = nullptr;
            Node *child = nullptr;
            while(parent){
                processChild(parent->left, child, firstChild);
                processChild(parent->right, child, firstChild);
                parent = parent->next;
            }
        }

        return root;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
