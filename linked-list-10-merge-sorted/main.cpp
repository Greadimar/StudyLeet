#include <QCoreApplication>
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
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val < l2->val){
            head = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            l2 = l2->next;

        }
        ListNode* cur = head;
        while (l1 != nullptr && l2 != nullptr){
            if (l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1 == nullptr) cur->next = l2;
        if (l2 == nullptr) cur->next = l1;
        return head;
    }
    static ListNode* mergeTwoListsBest(ListNode* l1, ListNode* l2){

        ListNode* p=NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        if(l1->val < l2->val)
        {
            p = l1;
            p->next = mergeTwoLists(l1->next,l2);
        }
        else
        {
            p = l2;
            p->next = mergeTwoLists(l1,l2->next);
        }
        return p;

    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    auto r = Solution::mergeTwoLists(l1, l2);
    return a.exec();
}
