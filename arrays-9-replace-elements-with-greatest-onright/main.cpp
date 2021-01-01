#include <QCoreApplication>
#include <QTime>
#include <QDebug>
using namespace std;
/*
 * Given an array arr, replace every element in that array with the greatest element among the elements to its right, and replace the last element with -1.

After doing so, return the array.
*/
class Solution {
public:
    static uint getMax(std::vector<int>::const_iterator it, vector<int>::const_iterator end){
        std::vector<int>::const_iterator ptrToMax = it;
        while(it != end){
            if (*it > *ptrToMax) ptrToMax = it;
            it++;
        }
        return *ptrToMax;
    };
    static  uint getMax2(int it, int&& end, const vector<int>& vec){
        int maxIt = it;
        for (; it < end; it++){
            if (vec[it] > vec[maxIt]) maxIt = it;
        }
        return vec[maxIt];

    };
    static vector<int> replaceElements(vector<int>& arr) {   //0(n^2)
        for (uint i = 0; i < arr.size() - 1; i ++){
            arr[i] = getMax2(i + 1, arr.size(), arr);
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
    static vector<int> replaceElements2(vector<int>& arr) {     //different result in leet? seems like optimization i++ inside function argument ruins it
        int i = 0;
        for (auto&& el: arr){                                   //0(n^2) - VERY BAD

            el = getMax2(i++, arr.size(), arr);
        }
        arr[arr.size()-1] = -1;
        return arr;
    }
    static vector<int> replaceElementsBest(vector<int>& arr) {    // O(N)
        int maximum = -1;
        int temp = 0;
        for (int i = arr.size() - 1; i >= 0; --i) {
            temp = arr[i];
            arr[i] = maximum;
            maximum = max(maximum, temp);
        }
        return arr;
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
//template < int times, template <typename T, typename T2> typename Fu, typename T, typename T2,
//           typename ...Args> void execNTimes(Fu<T, T2>&& fu, Args&&... args){
//    for (int i = 0; i < times; i++){
//        fu(std::forward<Args>(args)...);
//    }
//}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::vector<int> v{3,4,5,6,7,8,19,20,22,34};
    for (int i = 0; i < 10000; i++){
        v.push_back(i);
    }
    auto time1 = QTime::currentTime();

    execNTimes<10>(Solution::getMax, v.begin(), v.end());
    qDebug() << "bench getMax 1" << passedSince(time1);
    auto time2 = QTime::currentTime();

    execNTimes<10>(Solution::getMax2, 0, v.size(), v);
    qDebug() << "bench getMax 2" << passedSince(time2);                 //fastest

    //    auto lm = [](int& left, int& right){
    //        return left < right;
    //    };
    //    auto time3 = QTime::currentTime();
    //    execNTimes<100000>(std::sort<vector<int>::iterator, decltype (lm)>, v.begin(), v.end(), lm );
    //    qDebug() << "check sort" << passedSince(time3);

    auto time4 = QTime::currentTime();
    execNTimes<10>(std::max_element<vector<int>::iterator>, v.begin(), v.end());
    qDebug() << "bench maxel" << passedSince(time4);


    std::vector<int> t{17,18,5,4,6,1};
    qDebug() << "test fu 1:" << Solution::replaceElements(t);
    qDebug() << "test fu 2:" << Solution::replaceElements2(t);
        qDebug() << "test fu 3:" << Solution::replaceElementsBest(t);

    auto time5 = QTime::currentTime();
    execNTimes<1>(Solution::replaceElements, v);
    qDebug() << "bench re1" << passedSince(time5);

    auto time6 = QTime::currentTime();
    execNTimes<1>(Solution::replaceElements2, v);
    qDebug() << "bench re2" << passedSince(time6);
    auto time7 = QTime::currentTime();
    execNTimes<1>(Solution::replaceElementsBest, v);
    qDebug() << "bench re2" << passedSince(time7);

    return a.exec();
}
