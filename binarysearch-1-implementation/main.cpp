#include <QCoreApplication>
#include <QDebug>
class Solution {
public:
    static int getTargetIdx(const std::vector<int>& nums, const int& minIdx, const int& maxIdx, const int& target){
        if (nums[minIdx] == target) return minIdx;
        if (nums[maxIdx] == target) return maxIdx;
        if ((maxIdx - minIdx) <= 1) return -1;
        int mid = minIdx + (maxIdx - minIdx)/2;
        if (nums[mid] == target) return mid;
        if (nums[mid] > target) return getTargetIdx(nums, minIdx+1, mid-1, target);
        else if (nums[mid] < target) return getTargetIdx(nums, mid+1, maxIdx-1, target);
        else return -1;
    }
    static int search(const std::vector<int>& nums, int target) {
        if (nums.size() == 0) return target;
        if (nums[0] > target) return - 1;
        if (nums[nums.size()-1] < target) return - 1;
        return getTargetIdx(nums, 0, nums.size()-1, target);
    }

    int fastestSearch(std::vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (1) {
            int median = (start + end) / 2;
            if (start == end) {
                if (nums[median] == target) {
                    return median;
                } else {
                    return -1;
                }
            } else {
                if (nums[median] == target) {
                    return median;
                } else if (nums[median] > target) {
                    end = median;
                } else {
                    start = median + 1;
                }
            }
        }
        return -1;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() <<  Solution::search(std::vector<int>{-1,0,3,5,9,12}, 2);
    return a.exec();
}
