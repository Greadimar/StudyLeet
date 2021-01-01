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
    bool static isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        if (head->next == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* first = head;
        while(fast && (fast->next != nullptr)){
            fast = fast->next->next;
            ListNode* temp = slow;
            slow = slow->next;
            temp->next = first;
            first = temp;
        }
        if (fast) fast = slow->next;
        else fast = slow;
        head->next = slow;
        bool isPaly = true;
        while (fast != nullptr && isPaly){
            isPaly = (fast->val == first->val);
            fast = fast->next;
            first = first->next;
        }
        return isPaly;
    }
    bool isPalyndromeBest(ListNode* c){
        ListNode *reverse_list, *slow, *fast, *temp;

          slow = fast = c;
          reverse_list = new ListNode(0);

          while(slow != NULL && fast !=NULL && fast->next != NULL) {
              temp = slow;
              slow = slow->next;
              fast = fast->next->next;
              temp->next = reverse_list->next;
              reverse_list->next = temp;
              //cout << temp->val << endl;
          }

          temp = reverse_list;
          reverse_list = reverse_list->next;
          delete temp;

          if(reverse_list==NULL) {
              return true;
          }

          if(fast!=NULL) {
              slow = slow->next;
          }

          while(slow != NULL) {
              //cout << reverse_list->val << " - " << slow->val << endl;
              if(slow->val != reverse_list->val) {
                  return false;
                  break;
              }
              slow = slow->next;
              reverse_list = reverse_list->next;
          }

          return true;
      }

};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(1);
  //              head->next->next->next->next = new ListNode(1);
        auto r = Solution::isPalindrome(head);
    return a.exec();
}
