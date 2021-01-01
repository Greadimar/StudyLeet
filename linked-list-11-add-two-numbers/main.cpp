#include <QCoreApplication>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int countL1 = 0;
        int countL2 = 0;
        ListNode* p1 = l1, * p2 = l2;
        while (p1 != nullptr){
            countL1++;
            p1 = p1->next;
        }
        while (p2 != nullptr){
            countL2++;
            p2 = p2->next;
        }
        ListNode* sum = (countL1 > countL2)? l1 : l2;
        ListNode* rest = (countL1 > countL2)? l2 : l1;
        ListNode* headSum = sum;
        int mem = 0;
        while (rest != nullptr){
            sum->val = sum->val + rest->val;
            sum->val += mem;
            mem = 0;
            if(sum->val >= 10){ sum->val -= 10; mem++;};
            if (sum->next == nullptr && mem > 0){
                sum->next = new ListNode(mem);
                mem = 0;
            }
            sum = sum->next;
            rest = rest->next;
        }

        while (mem > 0){
            if (sum == nullptr){
                sum = new ListNode(mem);
                break;
            }
            sum->val += mem;
            mem = 0;
            if(sum->val >= 10){ sum->val -= 10; mem++;}
            if (sum->next == nullptr && mem > 0){
                sum->next = new ListNode(mem);
                break;
            }
            sum = sum->next;
        }
        return headSum;
    }

    ListNode* addTwoNumbersBest(ListNode* l1, ListNode* l2) {

           int reminder{};
           ListNode l3;
           ListNode *last = &l3;
           while(l1 || l2 || reminder){
               if(l1)
               {
                   reminder += l1->val;
                   l1 = l1->next;
               }
               if(l2)
               {
                   reminder += l2->val;
                   l2 = l2->next;
               }

               last->next = new ListNode{reminder%10};
               reminder = reminder/10;
               last = last->next;
           }

           return l3.next;
       }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ListNode* l1 = new ListNode(5);
//    l1->next = new ListNode(9);
//    l1->next->next = new ListNode(1);
    ListNode* l2 = new ListNode(5);
//    l2->next = new ListNode(9);
//    l2->next->next = new ListNode(9);
//        l2->next->next->next = new ListNode(9);
    auto r = Solution::addTwoNumbers(l1, l2);
    return a.exec();
}
