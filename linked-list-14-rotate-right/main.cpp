#include <QCoreApplication>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* cutTail(ListNode* head){

    }
    static ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int count = 0;
        auto cur = head;
        while (cur->next){
            cur = cur->next;
            count++;
        }
        count++;
        auto last = cur;
        int split = abs(count-(k%count) - 1);

        //full circle
        if (k % count == 0){
            return head;
        }
        //swap
        if (count == 2 && split == 1){
            last->next = head;
            head->next = nullptr;
            return last;
        }



        ListNode* updLast = head;
        ListNode* updFirst = head->next;
        for (int i = 0; i < split; i++){
            updLast = updLast->next;
            updFirst = updFirst->next;
        }
        //if (!updFirst->next) updFirst->next = head;
        last->next = head;
        updLast->next = nullptr;
        return updFirst;

    }


    ListNode* rotateRightBest(ListNode* head, int k)
    {
        if (head == NULL)
            return head;

        ListNode* newHead;
        ListNode* tail = head;
        int len = 1;

        while (tail->next)
        {
            len++;
            tail = tail->next;
        }

        k %= len;

        if (k == 0)
        {
            return head;
        }

        tail->next = head;

        int limit = len - k;
        while (limit--)
        {
            tail = tail->next;
        }

        newHead = tail->next;
        tail->next = NULL;

        return newHead;
    }
};

//         1  2  3  4  5
// n = 2
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto node = new ListNode(1);
    node->next = new ListNode(2);
    node->next->next = new ListNode(3);
    //    node->next->next->next = new ListNode(4);
    //        node->next->next->next->next = new ListNode(5);
    auto r = Solution::rotateRight(node,  4);      //2000000000
    return a.exec();
}
