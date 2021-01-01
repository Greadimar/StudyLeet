#include <QCoreApplication>


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    static ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* cur = head;
    ListNode* first = cur;
    while (cur != nullptr){
        ListNode* temp = cur;
        cur = cur->next;
        temp->next = first;
        first = temp;

    }
    head->next = nullptr;
    return first;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    ListNode * head = new ListNode(0);
//     head->next = new ListNode(2);

         ListNode * head2 = new ListNode(0);
         head2->next = new ListNode(1);
         head2->next->next = new ListNode(2);
         head2->next->next->next = new ListNode(3);
         head2->next->next->next->next = new ListNode(4);
         auto nh = Solution::reverseList(head2);
  //   auto r = Solution::reverseList(head);
    return a.exec();
};;
