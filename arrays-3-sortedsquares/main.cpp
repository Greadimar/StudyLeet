#include <QCoreApplication>
#include <QDebug>
#include <QTime>
using namespace std;
class Solution {
public:
    static vector<int> sortedSquares(vector<int>& a) {
        std::vector<int> b;
        int size = a.size();
        b.resize(size);
        for (int i = 0; i < size; i++){
            b[i] = a[i]*a[i];
        }
        std::sort(b.begin(), b.end());
        return b;
    }
    static vector<int> sortedSquaresSmart(vector<int>& A) {
        vector<int> ans(A.size(), 0);
        int left = 0;
        int right = A.size() - 1;
        for(int i = ans.size()-1; i >= 0; i--){
            if(abs(A[left]) > abs(A[right])){
                ans[i] = A[left] * A[left];
                left++;
            }else{
                ans[i] = A[right] * A[right];
                right--;
            }
        }
        return ans;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto b = QTime::currentTime();
    auto v= vector<int>{12,345,2,6,7896};
    long d =0 ;
    for(long i = 0; i < 10000000; i++) {d++; Solution::sortedSquares(v);}
    qDebug() << "t1"<< QTime::currentTime().msecsTo(b) * - 1;
    auto b2 = QTime::currentTime();
    for(long i = 0; i < 10000000; i++) {d--; Solution::sortedSquaresSmart(v);}
    qDebug() << "t2"<<QTime::currentTime().msecsTo(b2) * - 1;
    return a.exec();
}
