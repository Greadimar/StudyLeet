#include <QCoreApplication>
#include <QDebug>
/**
  Write a program to find the node at which the intersection of two singly linked lists begins.
// Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto itA = headA;
        int aCount = 0;
        while (itA != nullptr){ itA = itA->next; aCount++;}
        auto itB = headB;
        int bCount = 0;
        while (itB != nullptr){ itB = itB->next; bCount++;}

        auto aPtr = headA;
        auto bPtr = headB;
        if (aCount > bCount){
            for (int i = 0; i < aCount - bCount; i++){
                aPtr = aPtr->next;
            }
        }
        else {
            for (int i = 0; i < bCount - aCount; i++){
                bPtr = bPtr->next;
            }
        }
        while (aPtr != bPtr){
            aPtr = aPtr->next;
            bPtr = bPtr->next;
            if (aPtr == nullptr || bPtr == nullptr) return nullptr; //don't need may be
        }
        return aPtr;

    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ListNode* aHead = new ListNode(0);
    ListNode* ptr = aHead;
    for (int i = 1; i < 6; i++){
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }
    ListNode* bHead = new ListNode(0);
    ListNode* ptr2 = bHead;
    for (int i = 1; i < 2; i++){
        ptr2->next = new ListNode(i);
        ptr2 = ptr2->next;
    }
    bHead->next->next = aHead->next->next->next->next;
    qDebug() << Solution::getIntersectionNode(aHead, bHead)->val;
    return a.exec();
}
