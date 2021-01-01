#include <QCoreApplication>
#include <QDebug>
/*
 *
 * Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/
using namespace std;
class Solution {
public:
    static vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::vector<int> result;
        for (int i = 0; i < nums.size(); i++){
            for (int i = 0; i < nums.size(); i++) {
                int val = abs(nums[i]) - 1;
                if (nums[val] > 0) {
                    nums[val] = -nums[val];
                }
            }
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > 0) {
                    result.push_back(i + 1);
                }
            }
            return result;
        }
        return result;
    }
    vector<int> findDisappearedNumbers2(vector<int>& nums) {
          const int s = nums.size();
          for(int i = 0; i < s; i++) {
              int idx = abs(nums[i]) - 1;
              nums[idx] = abs(nums[idx]) * -1;
          }
          int val = 1;
          int count = 0;
          for(auto v : nums) {
              if(v > 0) {
                  nums[count] = val;
                  count++;
              }
              val++;
          }
          return vector(nums.begin(), nums.begin() + count);
      }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int>v{1,1};
    qDebug() << Solution::findDisappearedNumbers(v);
    return a.exec();
}
