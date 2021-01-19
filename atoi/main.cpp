#include <QCoreApplication>
#include <QDebug>
using namespace std;
#include "iostream"
#include <numeric>
constexpr bool isNumeric(const char c){     //if constexpr ; else if constexpr etc DOESN'T WORK
    return (c <= '9' && c > '0') ;
}

template <size_t Size>
constexpr int sum(const int (&arr)[Size])
{
    int ret = 0;
    for (int i = 0; i < Size; ++i)
        ret += arr[i];
    return ret;
}
int myAtoi(string s) {
   int res{0};
   int d = 0;
   char t[s.size()];
   bool isMinus{0};
   if (s.at(0) == *("-")) isMinus = true;
   for (int i = 0; i < s.size(); i++){ //swap to constexpr recursive
       auto&& c = s[i];
       if (isNumeric(c)){t[d] = c - ''; d++;}
       else break;
   }
   res = static_cast<int>(*t);

   return res;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << myAtoi("991s");
    return a.exec();
}
