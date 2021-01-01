#include <QCoreApplication>
#include <QTime>
#include <QDebug>
using namespace std;
/*
 *Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * */
class Solution {
public:
    static void moveZeroes(vector<int>& nums) {             //very bad approach. should think better
        uint notZeroIt = 0;             //source iterator where we f
        bool overflow = false;
        for (int i = 0; i < nums.size(); i++){

            if (notZeroIt < nums.size()){

                while (nums[notZeroIt] == 0){
                    notZeroIt++;
                    if (notZeroIt >= nums.size()){overflow = true; break;}
                }
                if(!overflow) nums[i] = nums[notZeroIt]; else nums[i] = 0;
                notZeroIt++;
            }
            else nums[i] = 0;

        }
    }
    static void moveZeroesBest(vector<int>& nums) {
        int end_nonzeroes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[end_nonzeroes] = nums[i];
                end_nonzeroes++;
            }
        }
        for (int i = end_nonzeroes; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
int passedSince(QTime& time){
    return -1*QTime::currentTime().msecsTo(time);
}
template <int times, typename Fu, typename ...Args> void execNTimes(Fu&& fu, Args&&... args){
    for (int i = 0; i < times; i++){
        fu(std::forward<Args>(args)...);
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::vector<int> v{0,2,4,0,2,6,12,0,0,12,0};
    Solution::moveZeroes(v);
    qDebug() << "test 1" << v;
    return a.exec();
}
