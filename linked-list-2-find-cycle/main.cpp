#include <QCoreApplication>
/*
 * Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* cur = head;
        while (cur != NULL){
            if (cur->val == INT_MIN) return true;
            cur->val = INT_MIN;
            cur = cur->next;
        }
        return false;
    }
    bool hasCycleBest(ListNode *head) {
        auto slow = head, fast = head;
        while (fast != nullptr)
        {
            slow = slow->next;

            fast = fast->next;
            if (fast == nullptr)
                return false;
            fast = fast->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
