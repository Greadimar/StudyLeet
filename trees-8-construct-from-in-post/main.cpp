#include <QCoreApplication>
#include <unordered_set>
#include <unordered_map>
using namespace std;
//  Definition for a binary tree node.
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


     TreeNode* toFillLeft(const unordered_map<int, int>& inMap, const std::unordered_map<int, int>& postMap,
                     const vector<int>& inVec, const vector<int>& postVec, int itInRight, int itInLeft){

          int mostRightInLeft = -1;
          TreeNode* n = nullptr;
          for (int i = itInLeft; i < itInRight; i++){
              int curIt =  postMap.find(inVec[i])->second;
              if (mostRightInLeft < curIt) mostRightInLeft = curIt;
          }
          if (mostRightInLeft >= 0){
              n = new TreeNode(postVec[mostRightInLeft]);
              int itNInOrder = inMap.find(n->val)->second;
              n->left = toFillLeft(inMap, postMap, inVec, postVec, itNInOrder, itInLeft);
              n->right = toFillRight(inMap, postMap, inVec, postVec, itInRight, itNInOrder + 1);
          };
          return n;

     }
     TreeNode* toFillRight(const unordered_map<int, int>& inMap, const std::unordered_map<int, int>& postMap,
                     const vector<int>& inVec, const vector<int>& postVec, int itInRight, int itInLeft){
        // int inordIt = inMap.find(postVec[itRight])->second;
         int mostRightInLeft = -1;
         TreeNode* n = nullptr;
         for (int i = itInLeft; i < itInRight; i++){
             int curIt =  postMap.find(inVec[i])->second;
             if (mostRightInLeft < curIt) mostRightInLeft = curIt;
         }
         if (mostRightInLeft >= 0){
             n = new TreeNode(postVec[mostRightInLeft]);
              int itNInOrder = inMap.find(n->val)->second;
             n->left = toFillLeft(inMap, postMap, inVec, postVec, itNInOrder, itInLeft);
             n->right = toFillRight(inMap, postMap, inVec, postVec, itInRight, itNInOrder + 1);
         };
         return n;

     }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

       if (inorder.size() == 0) return  nullptr;
       std::unordered_map<int, int> inMap{};
       std::unordered_map<int, int> postMap{};
       for (int i = 0; i < static_cast<int>(inorder.size()); i++){
           inMap.insert({inorder[i], i});
           postMap.insert({postorder[i], i});
       }
       TreeNode* root  = new TreeNode(postorder.back());

        root->left = toFillLeft(inMap, postMap,inorder, postorder, (*(inMap.find(postorder.back()))).second, 0);
        root->right = toFillRight(inMap, postMap, inorder, postorder, inorder.size(), (*(inMap.find(postorder.back()))).second +1);


       return root;

    }
};

class SolutionFast{
    class Solution {
    public:

    TreeNode* buildTree(int pStart, int pEnd, int iStart, int iEnd){
        if (pStart==pEnd || pStart>pEnd || iStart>iEnd) return NULL;
        int rootVal = postOrder[pEnd-1];
        TreeNode* root = new TreeNode(rootVal);
        int posRoot = map[rootVal];
        int left = posRoot-iStart;
        root->left = buildTree(pStart, pStart+left, iStart,posRoot);
        root->right = buildTree(pStart+left, pEnd-1,posRoot+1,iEnd);
        return root;
    }

        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            inOrder = inorder;
            postOrder = postorder;
            if(inorder.empty() || postorder.empty()) return NULL;
            int pStart = 0;
            int iStart = 0;
            int pEnd = postorder.size();
            int iEnd = inorder.size();
            for(int i=0; i<iEnd; ++i){
                map[inorder[i]] = i;
            }
            TreeNode* root = buildTree(pStart,pEnd,iStart,iEnd);
            return root;
        }

    private:
        vector<int> inOrder;
        vector<int> postOrder;
        unordered_map<int,int> map;
    };
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::vector<int> io{9,3,15,20,7};
    std::vector<int> po{9,15,7,20,3};
    auto p = Solution().buildTree(io, po);
    return a.exec();
}
