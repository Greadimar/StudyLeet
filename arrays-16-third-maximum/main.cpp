#include <QCoreApplication>
#include <QDebug>
using namespace std;
class Solution {
public:
    static int thirdMax(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return nums[1];
        int maxCount = 1;
        int max = nums[nums.size() - 1];
        for (int i = nums.size()-2; i >= 0; i--){
            if (nums[i] < max){

                maxCount ++;
                max = nums[i];
                if (maxCount == 3) return max;
            }
        }
        return nums[nums.size()-1];

    }

    static int thirdMaxBest(vector<int>& nums){
        int *a, *b, *c;
       a = b = c = NULL;
       for (int i = 0; i < nums.size(); ++i) {
          if (!a || nums[i] >= *a) {
             if (a && nums[i] > *a) {
                c = b;
                b = a;
             }
             a = &nums[i];
          }
          else if (!b || nums[i] >= *b) {
             if (b && nums[i] > *b) {
                c = b;
             }
             b = &nums[i];
          }
          else if (!c || nums[i] >= *c) {
             c = &nums[i];
          }
       }
       return !c ? *a : *c;
    }

    int thirdMaxBest2(vector<int>& nums) {
         long first = std::numeric_limits<long>::min(), second = std::numeric_limits<long>::min() , third = std::numeric_limits<long>::min();
         for (auto x : nums){
             if (x > first){
                 third = second;
                 second = first;
                 first = x;
             } else if (x > second && x != first){
                 third = second;
                 second = x;
             } else if (x > third && x != second && x != first){
                 third = x;
             }
         }
         return third == std::numeric_limits<long>::min()? static_cast<int>(first) : static_cast<int>(third);
     }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::vector<int> v{1,1,2};
    qDebug() << Solution::thirdMax(v);
    return a.exec();
}
