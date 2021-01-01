#include <QCoreApplication>
#include <QDebug>
/*Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

You may return any answer array that satisfies this condition.
*/
using namespace std;
class Solution {
public:
    static inline bool isEven(int& v){ return v%2 == 0;}
    static vector<int> sortArrayByParity(vector<int>& nums) {
        int oddIt = nums.size() -1;
        for (int evenIt = 0; evenIt < oddIt; evenIt++){
            auto&&el = nums[evenIt];
            if (isEven(el)){
                continue;
            }
            if (!isEven(el)){
                while (!isEven(nums[oddIt])){
                    oddIt --;
                    if (oddIt == evenIt){break;}
                }
                std::swap(el, nums[oddIt]);
            }
        }
        return nums;
    }
    static vector<int> sortArrayByParityBest(vector<int>& A)
        {
            int i = 0;
            int j = A.size() - 1;

            while(i < j)
            {
                while(i < j && A[i]%2 == 0) i++;
                while(i < j && A[j]%2 == 1) j--;

                if(i < j)
                {
                    int temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
            return A;
        }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
       std::vector<int>v{0, 3,2,1, 13, 11, 20, 12};
       qDebug() << "test:" << Solution::sortArrayByParity(v);
    return a.exec();
}
