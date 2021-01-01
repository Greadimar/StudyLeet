#include <QCoreApplication>
#include <QDebug>
/*
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < A[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
*/
using namespace std;
class Solution {
public:
    static bool validMountainArray(const vector<int>& arr) {        //my implementation
        if (arr.size() <= 2) return false;
        bool peak = false;
        if (arr[1] <= arr[0]) return false;
        int j = -1;
        for (auto&& curEl: arr){
            if (j < 1){
                j++;
                continue;
            }
            if (curEl < arr[j]){
                if (!peak) peak = true;
            }
            else{
                if (curEl == arr[j]) return false;
                if (peak) return false;
            }
            j++;
        }
        return peak;
    }
    static bool validMountainArrayBest(const vector<int>& arr){
        int i = 1 , j = 2 , n = arr.size();
        if (n <= 1) {
            return 0;
        }
        if (arr[1] < arr[0]) {
            return 0;
        }
        int f = 1;
        while (j < n) {
            if (arr[i] < arr[j]) {
                if (f != 1) {
                    return 0;
                }
            }
            else if (arr[i] > arr[j]) {
                if (f == 1) {
                    f = 2;
                }
                else if (f == 1) {
                    return 0;
                }
            }
            else {
                return 0;
            }
            i++;
            j++;
        }
        return f==2;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << Solution::validMountainArray({3,4,6,8,2,1}); //true
    qDebug() << Solution::validMountainArray({3,4,6,8,9,10}); //false
    qDebug() << Solution::validMountainArray({3,2,6,8,9,6}); //false
    qDebug() << Solution::validMountainArray({1,3,4}); //false
    qDebug() << Solution::validMountainArray({1,2,5,1}); //true
    qDebug() << Solution::validMountainArray({3,2,6,8,9,6}); //false
    qDebug() << Solution::validMountainArray({3,3,6,8,9,6}); //false
    qDebug() << Solution::validMountainArray({3,9,6}); //true
    qDebug() << Solution::validMountainArray({3,9,10,12,12, 9}); //false
    return a.exec();
}
