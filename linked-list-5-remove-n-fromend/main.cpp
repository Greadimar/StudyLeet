#include <QCoreApplication>

/*
  Given the head of a linked list, remove the nth node from the end of the list and return its head.
 */


//* Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static bool nextExist(ListNode* head, int n){
        ListNode *cur = head;
        for (int i = 0; i < n; i++){
            if (cur->next != nullptr){
                cur = cur->next;
            }
            else return false;
        }
        return true;
    }
    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto fastPtr = head;
          auto slowPtr = head;
          while (fastPtr != nullptr){
              if (nextExist(fastPtr, n)){
                  slowPtr = fastPtr;
                  fastPtr = fastPtr->next;
              }
              else break;
          }
          if (fastPtr == nullptr) return nullptr;
          if (slowPtr == fastPtr && fastPtr == head) head = slowPtr->next;
//              head->next = nullptr;
//              return head;}
          if (slowPtr == fastPtr) slowPtr->next = fastPtr->next;
          else slowPtr->next = fastPtr->next;;
          return head;
    }
    static ListNode* removeNthFromEndBest(ListNode* head, int n) {
        ListNode* slow = head, *fast = head;
             for(int i = 0; i < n; i++)  fast = fast->next;

             if(fast == NULL)
                 return head->next;

             while(fast->next != NULL)
             {
                 fast = fast->next;
                 slow = slow->next;
             }

             slow->next = slow->next->next;
             return head;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
   ListNode * head = new ListNode(0);
    head->next = new ListNode(2);

    auto r = Solution::removeNthFromEnd(head, 2);
//    ListNode * head2 = new ListNode(0);
//    head2->next = new ListNode(1);
//    head2->next->next = new ListNode(2);
//    head2->next->next->next = new ListNode(3);
//    head2->next->next->next->next = new ListNode(4);
//    auto nh = Solution::removeNthFromEnd(head2, 2);
    return a.exec();
}
