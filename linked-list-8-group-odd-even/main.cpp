#include <QCoreApplication>
/*
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
*/

#pragma GCC optimize("Ofast")
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    static bool isEven(int t){
        return t%2 == 0;
    }
    static ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return head;
              ListNode* firstEven = head->next;
            ListNode* even = head->next;
            if (even == nullptr) return head;
            ListNode* odd = head;
            while (even->next != nullptr){
                odd->next = even->next;
                odd = even->next;
                even->next = odd->next;
                            if (odd->next == nullptr) break;
                even = even->next;


            }
            odd->next = firstEven;

            return head;

    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        auto r = Solution::oddEvenList(head);
    return a.exec();
}
