#include <QCoreApplication>
//Remove all elements from a linked list of integers that have value val.

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
    static ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode* cur = head;
        ListNode* previous = cur;

        while (head != nullptr && cur == head){
            if (cur->val == val){
                head = head->next;
                cur = cur->next;
                continue;
            }
            cur = cur->next;
        }
        previous = cur;
        while (cur != nullptr){
            if (cur->val == val){
                if (cur == head){
                    head = head->next;
                }
                previous->next = cur->next;
                cur = cur->next;
                continue;
            }
            previous = cur;
            cur = cur->next;
        }
        return head;
    }
    static ListNode* removeElementsBest(ListNode* head, int val) {
        if (head == nullptr) return nullptr;

            while(head && head->val == val){
                head = head->next;
            }

            if(head){
                ListNode *it = head;
                while(it->next){
                    if(it->next->val == val){
                        it->next = it->next->next;
                    }
                    else{
                        it = it->next;
                    }
                }
            }
            return head;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    auto r = Solution::removeElements(head, 1);
    return a.exec();
}
