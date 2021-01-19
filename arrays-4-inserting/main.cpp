#include <QCoreApplication>
#include <QDebug>
#include <QTime>
class Solution {
public:
    //fastest
    static void duplicateZeros(std::vector<int>& arr) {
          int zeroes = count(arr.begin(), arr.end(), 0);
          int i = arr.size() - 1;
          int j = i + zeroes;

          while (i != j) {
              if (!arr[i]) {
                  insert(arr, i, j--);
              }
              insert(arr, i, j--);
              i--;
          }
      }

  private:
      static void insert(std::vector<int>& arr, int i, int j) {
          int length = arr.size();
          if (j < length) {
              arr[j] = arr[i];
          }
      }
  public:
      //mine
    static void duplicateZeros2(std::vector<int>& arr){
        std::vector<int> res;
        res.reserve(arr.size() + 100);
        for (uint i = 0; i < arr.size(); i++){
            if (res.size() >= arr.size()) break;
            res.push_back(arr[i]);
            if (arr[i] == 0) res.push_back(0);

        }
        for (uint i = 0; i < arr.size(); i++){
            arr[i] = res[i];
        }

        //        for (;it < arr.end(); it++){
        //            if (*it == 0){it++; arr.insert(it, 0);}
        //        }
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto b = QTime::currentTime();
    auto v= std::vector<int>{0,0,3,0,4,0,0};
    auto v2 = v;
    Solution::duplicateZeros(v);
    qDebug() << v;
    Solution::duplicateZeros2(v2);
    qDebug() << v2;

     for(long i = 0; i < 100000; i++) {Solution::duplicateZeros(v);}
    qDebug() << "t1"<< QTime::currentTime().msecsTo(b) * - 1;
    auto b2 = QTime::currentTime();
    for(long i = 0; i < 100000; i++) {Solution::duplicateZeros2(v2);}
    qDebug() << "t2"<<QTime::currentTime().msecsTo(b2) * - 1;

    return a.exec();
}
