#include <QCoreApplication>
#include <QDebug>
#include <QTime>
using namespace std;
class Solution {
public:
    static int findMaxConsecutiveOnes(const vector<int>& nums) {
        int curDigit{-1};
        int curDigitCounter{0};
        //int digitOfMaxCount{-1};
        int maxDigitCount{0};

        const int targetDigit{1};
        for (size_t i = 0; i < nums.size(); i++){
            int nextdigit = nums.at(i);
            if (nextdigit != curDigit){
                curDigit = nextdigit;
                curDigitCounter = 0;
            }
            curDigitCounter++;
            if ((maxDigitCount < curDigitCounter) && (curDigit == targetDigit)){
                //if (digitOfMaxCount != curDigit) digitOfMaxCount = curDigit;
                maxDigitCount = curDigitCounter;
            }
        }
        return maxDigitCount;
    }
    static int findMaxConsecutiveOnes2(const vector<int>& nums) {
        int curDigitCounter{0};
        int maxDigitCount{0};
        int size = nums.size();
        for (int i = 0; i < size; i++){
            const int& curDigit = nums[i];
            if (curDigit != 1){
                curDigitCounter = 0;
            }
            else{
                curDigitCounter++;
            }
            if (maxDigitCount < curDigitCounter){
                maxDigitCount = curDigitCounter;
            }
        }
        return maxDigitCount;
    }

};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto b = QTime::currentTime();
    const auto v= vector<int>{1,0,1,1,0,1};
    long d =0 ;
    for(long i = 0; i < 10000000; i++) {d++; Solution::findMaxConsecutiveOnes(v);}
    qDebug() << "t1"<< QTime::currentTime().msecsTo(b) * - 1;
    auto b2 = QTime::currentTime();
    for(long i = 0; i < 10000000; i++) {d--; Solution::findMaxConsecutiveOnes2(v);}
    qDebug() << "t2"<<QTime::currentTime().msecsTo(b2) * - 1;
    return a.exec();
}
