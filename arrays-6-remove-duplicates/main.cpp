#include <QCoreApplication>
#include <QDebug>
#include <QTime>
/*
 * Given a sorted array nums, remove the duplicates in-place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
*/
using namespace  std;
class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int cur = 0;
        for (uint i = 0; i < nums.size() - 1; i++){
            if (nums[i] == nums[i + 1])
                continue;
            else{
                nums[cur] = nums[i];
                cur++;
            }
        }
        nums[cur++] = nums[nums.size() - 1];
        return cur;
    }
    static int removeDuplicatesBest(vector<int>& v) {
        if(v.size()<=1)
            return v.size();

        int index=0;
        v[index++]=v[0];

        for(uint i=1;i<v.size();i++)
        {
            if(v[i]==v[index-1])
                continue;
            else
                v[index++]=v[i];
        }
        return index;
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
    std::vector<int> vec{};
    int res = Solution::removeDuplicates(vec);
    qDebug() << vec << "res"<<res;
    return a.exec();
}
