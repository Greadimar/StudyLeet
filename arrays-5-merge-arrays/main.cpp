#include "widget.h"
#include "vector"
#include <QApplication>
using namespace std;
class Solution {
public:
    static void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        /*   int bufIt = m;
        int size = m+n;
        int itn1{0}, itn2{0};
        for (int i = 0; i < m+n; i++){
            bool n1Exists = itn1 < m;
            bool n2Exists = itn2 < n;

            if (n1Exists && n2Exists){
                if (nums1[itn1] < nums2[itn2]){
                    if (nums1[bufIt] < nums1[itn1]){
                        nums1[bufIt + 1] = nums1[i];
                        bufIt ++;
                        while (bufIt >= m){
                            nums1[i] = size - bufIt;
                        }
                    }
                    itn1++;
                }
                else{
                    if (itn2 < n){
                        nums1[bufIt] = nums1[i];
                        bufIt++;
                        nums1[i] = nums2[itn2];
                        itn2++;
                    }
                }
            }
            else{
                if (n2Exists && !n1Exists){
                    res[i] = nums2[itn2];
                    itn2++;
                }
                if (n1Exists && !n2Exists){
                    res[i] = nums1[itn1];
                    itn1++;
                }

            }

        }
        nums1.swap(res);*/
    }
    static void merge2(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int size = m+n;
        int itn1{m-1}, itn2{n-1};
        if (n == 0 && m == 0) return;
        if (n == 0 && m != 0){
            std::sort(nums1.begin(), nums1.end());
            return;
        }
        if (m == 0 && n != 0){
            nums1 = nums2;
            return;
        }
        for (int i = size - 1; i > -1; i--){
            if (itn2 < 0 && itn1 >= 0){
                auto&& curn1 = nums1[itn1];
                nums1[i] = curn1;
                itn1--;
                continue;
            }
            if (itn1 < 0 && itn2 >= 0){
                auto&& curn2 = nums2[itn2];
                nums1[i] = curn2;
                itn2--;
                continue;
            }


            auto&& curn2 = nums2[itn2];
            auto&& curn1 = nums1[itn1];
            if (curn2 > curn1){
                nums1[i] = curn2;
                itn2-- ;
            }
            else{
                nums1[i] = curn1;
                itn1--;
            }
        }


    }

    static double findMeanSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(); int n = nums2.size();
        int size = m+n;
        nums1.resize(size);
        int sum = 0;
        int itn1{m-1}, itn2{n-1};
        if (n == 0 && m == 0) return 0;
        if (n == 0 && m != 0){
            std::sort(nums1.begin(), nums1.end());
            sum = std::accumulate(nums1.begin(), nums1.end(), 0);
            return sum/static_cast<double>(size);
        }
        if (m == 0 && n != 0){

            sum = std::accumulate(nums2.begin(), nums2.end(), 0);
            return sum/static_cast<double>(size);
        }
        for (int i = size - 1; i > -1; i--){
            if (itn2 < 0 && itn1 >= 0){
                auto&& curn1 = nums1[itn1];
                nums1[i] = curn1;
                sum += curn1;
                itn1--;
                continue;
            }
            if (itn1 < 0 && itn2 >= 0){
                auto&& curn2 = nums2[itn2];
                nums1[i] = curn2;
                sum += curn2;
                itn2--;
                continue;
            }


            auto&& curn2 = nums2[itn2];
            auto&& curn1 = nums1[itn1];
            if (curn2 > curn1){
                nums1[i] = curn2;
                sum += curn2;
                itn2-- ;
            }
            else{
                nums1[i] = curn1;
                sum += curn1;
                itn1--;
            }
        }
        return static_cast<double>(sum)/size;
    }

    static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(); int n = nums2.size();
        int size = m+n;
        nums1.resize(size);
        bool isEven = (size%2 == 0);
        int evenFirstMedianIt = isEven? static_cast<int>(size/2) - 1 : size/2;
        double sum = 0;
        int itn1{m-1}, itn2{n-1};



        if (n == 0 && m == 0) return 0;
        if (n == 0 && m != 0){
            // n is even
            auto itr = nums1.begin();
            if( isEven ) {
                for( uint i = 0 ; i < nums1.size() / 2 ; i ++ ) {
                    itr++;
                }

                sum = ( (double)*itr + *--itr ) / 2;
            }
            // n is odd
            else {
                for( uint i = 0 ; i < nums1.size() / 2 ; i ++ ) {
                    itr++;
                }

                sum = *itr;
            }
            return sum;
        }
        if (m == 0 && n != 0){
            auto itr = nums2.begin();
            if( isEven ) {
                for( uint i = 0 ; i < nums2.size() / 2 ; i ++ ) {
                    itr++;
                }

                sum = ( (double)*itr + *--itr ) / 2;
            }
            // n is odd
            else {
                for( uint i = 0 ; i < nums2.size() / 2 ; i ++ ) {
                    itr++;
                }

                sum = *itr;
            }
            return sum;
        }



        for (int i = size - 1; i > -1; i--){
            if (itn2 < 0 && itn1 >= 0){
                auto&& curn1 = nums1[itn1];
                nums1[i] = curn1;
                if (evenFirstMedianIt == i)
                    sum = curn1;



                itn1--;
                continue;
            }
            if (itn1 < 0 && itn2 >= 0){
                auto&& curn2 = nums2[itn2];
                nums1[i] = curn2;
                if (evenFirstMedianIt == i)

                    sum = curn2;

                itn2--;
                continue;
            }


            auto&& curn2 = nums2[itn2];
            auto&& curn1 = nums1[itn1];
            if (curn2 > curn1){
                nums1[i] = curn2;
                if (evenFirstMedianIt == i){

                    sum = curn2;
                }
                itn2-- ;
            }
            else{
                nums1[i] = curn1;
                if (evenFirstMedianIt == i)

                    sum = curn1;

                itn1--;
            }
        }
        if (isEven){
            sum += nums1[evenFirstMedianIt+1];
            return sum/2.0;
        }
        else return sum;
        return static_cast<double>(sum)/size;
    }
};



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    std::vector<int> v{4,5,6,0,0,0};
    std::vector<int> t{1, 2, 3};
    Solution::merge2(v, 3, t, 3);
    std::vector<int> v2{1, 3};
    std::vector<int> t2{2};
    double k = Solution::findMedianSortedArrays(v2, t2);
    w.show();
    return a.exec();
}
