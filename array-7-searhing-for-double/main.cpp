#include <QCoreApplication>
#include <QDebug>
#include <unordered_set>
using namespace std;
class Solution {
public:
    static bool isDouble(const int& estimatedDouble, const int& checkingEl){
        return ((checkingEl*2) == estimatedDouble);
    }
    static bool checkIfExist(const vector<int>& arr) {
        for (uint i = 0; i < arr.size(); i++){
            for (uint j = 0; j < arr.size(); j++){
                if (i == j) continue;
                auto && estimatedDouble = arr[i];
                if (isDouble(estimatedDouble, arr[j]))
                    return true;
                else continue;
            }
        }
        return false;
    }
    static bool  checkIfExistBest(const vector<int>& arr) {
        std::unordered_set<int> valset;
        for (const int& i : arr) {
            if (valset.find(i*2) != valset.end()) {
                return true;
            }
            else if ((i % 2 == 0) && (valset.find(i / 2) != valset.end())) {
                return true;
            }
            valset.insert(i);
        }
        return false;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::vector<int>{3,4,10,5,8,9};

    qDebug() << Solution::checkIfExistBest({3,4,10,5,8,9});
    qDebug() << Solution::checkIfExist({3,4,3,2,2,8});
    qDebug() << Solution::checkIfExist({});
    qDebug() << Solution::checkIfExist({1,1});
    qDebug() << Solution::checkIfExist({-2,0,10,-19,4,6,-8});
    return a.exec();
}
