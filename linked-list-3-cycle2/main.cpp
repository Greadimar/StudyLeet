#include <QCoreApplication>
#include "myll.h"
#include <QDebug>
#include <unordered_set>
/*
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Notice that you should not modify the linked list.
*/
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    static ListNode *detectCycle(ListNode *head) {  //basic approach
        // If list is empty or has only one node
          // without loop
          if (head == NULL || head->next == NULL)
              return NULL;

          ListNode *slow = head, *fast = head;

          // Move slow and fast 1 and 2 steps
          // ahead respectively.
          slow = slow->next;
          fast = fast->next->next;

          // Search for loop using slow and
          // fast pointers
          while (fast && fast->next) {
              if (slow == fast)
                  break;
              slow = slow->next;
              fast = fast->next->next;
          }

          // If loop does not exist
          if (slow != fast)
              return NULL;

          // If loop exists. Start slow from
          // head and fast from meeting point.
          slow = head;
          while (slow != fast) {
              slow = slow->next;
              fast = fast->next;
          }

          return slow;
    }
    static ListNode *detectCycle2(ListNode *head) {  //with temp node
        // Create a temporary node
        ListNode* temp = new ListNode(0);
        while (head != nullptr)
        {

            // This condition is for the case
            // when there is no loop
            if (head->next == nullptr)
            {
                return nullptr;
            }

            // Check if next is already
            // pointing to temp
            if (head->next == temp)
            {
                break;
            }

            // Store the pointer to the next node
            // in order to get to it in the next step
            ListNode* nex = head->next;

            // Make next point to temp
            head->next = temp;

            // Get to the next node in the list
            head = nex;
        }

        return head;
    }
    static ListNode *detectCycle3(ListNode *head) {  //with set
        // Create a temporary node
       std:: unordered_set<ListNode*> uset;

        ListNode *ptr = head;

        // Default consider that no cycle is present
        while (ptr != NULL) {

            // checking if address is already present in map
            if (uset.find(ptr) != uset.end())
              return ptr;

            // if address not present then insert into the set
            else
                uset.insert(ptr);

            ptr = ptr->next;
        }
        return NULL;
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    ListNode arr[]{{3},{2},{0},{-4}};
//    arr[0].next = &arr[1];
//    arr[1].next = &arr[2];
//    arr[2].next = &arr[3];
//    arr[3].next = &arr[1];
    ListNode arr[]{{1},{2}, {3}};
    arr[0].next = &arr[1];
    arr[1].next = &arr[2];
    arr[2].next = &arr[1];
    qDebug() << Solution::detectCycle(&arr[0])->val;
    return a.exec();
}
