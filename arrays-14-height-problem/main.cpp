
#include <QCoreApplication>

/*
Students are asked to stand in non-decreasing order of heights for an annual photo.

Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.

Notice that when a group of students is selected they can reorder in any possible way between themselves and the non selected students remain on their seats.
*/
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::vector<int> res{heights};
        std::sort(res.begin(), res.end());
        int moves = 0;
        for (int i = 0; i < heights.size(); i++){
            if (heights[i] != res[i]) moves++;
        }
        return moves;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
