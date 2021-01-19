#include <QCoreApplication>
#include <QDebug>
#include <QTime>
using namespace std;
class Solution {
public:
    static int findNumbers(std::vector<int>& nums) {
        int res{0};
        for (int i = 0; i < nums.size(); i++){
            const int& val = nums[i];
            if (val >= 10 && val < 100) res++;
            else if( val >= 1000 && val < 10000) res++;
            else if(val >= 100000 ) res ++;
            else continue;
        }
        return res;
    }
    static int findNumbersFast(std::vector<int>& nums) {
        int a=0, b=0, c=1;
        for(int i=0; i<nums.size(); i++){
            while(nums[i]/10!=0){
                nums[i] = nums[i]/10;
                c++;
            }
            if(c%2==0){
                a++;
            }
            c=1;
        }
        return a;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto b = QTime::currentTime();
    auto v= vector<int>{12,345,2,6,7896};
    long d =0 ;
    for(long i = 0; i < 10000000; i++) {d++; Solution::findNumbers(v);}
    qDebug() << "t1"<< QTime::currentTime().msecsTo(b) * - 1;
    auto b2 = QTime::currentTime();
    for(long i = 0; i < 10000000; i++) {d--; Solution::findNumbersFast(v);}
    qDebug() << "t2"<<QTime::currentTime().msecsTo(b2) * - 1;
    return a.exec();
}
