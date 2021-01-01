#include <QCoreApplication>
/*
 * Given an integer array nums sorted in non-decreasing order,
 * return an array of the squares of each number sorted in non-decreasing order.
 * */


using namespace  std;
#include <QDebug>

class Solution {
public:
    static vector<int> sortedSquares(vector<int>& nums) {
          std::vector<int> result(nums.size());
          int resIt = nums.size() - 1;
          uint rightIt = resIt;
          uint leftIt = 0;
          while (rightIt >= leftIt){

               auto rightSq = nums[rightIt] * nums[rightIt];        //should check abs first and than calc square
               auto leftSq = nums[leftIt] * nums[leftIt];
               if (rightSq > leftSq){
                   result[resIt] = rightSq;
                   rightIt--;
               }
               else{
                   result[resIt] = leftSq;
                   leftIt++;
               }
               resIt --;
          }
          return result;
    }

    vector<int> sortedSquaresBest(vector<int>& A) {
        int l = 0, r = A.size()-1;
        vector<int> result;
        while(l <= r){
            if(abs(A[l]) < abs(A[r])){
                result.push_back(A[r] * A[r]);
                r--;
            }else{
                result.push_back(A[l] * A[l]);
                l++;
            }
        }
        reverse(result.begin(), result.end());
        return result;
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::vector<int> t{-4,-1,0,3,10};
    qDebug() << Solution::sortedSquares(t);
    return a.exec();
}
