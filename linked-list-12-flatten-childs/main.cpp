#include <QCoreApplication>
// Definition for a Node.
/*You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.



Example 1:

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
//nulls are margins from begin of child ???
*/
struct HeadTag{};
struct TailTag{};
struct Node {

    int val;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node* child = nullptr;
    Node(int v):val(v) {};
    Node(int v, Node* n, Node* p):val(v), next(n), prev(p) {};
    Node(int v, Node* n, HeadTag):val(v), next(n) {};
    Node(int v, Node* p, TailTag):val(v), prev(p) {};
};

class Solution {
public:
    static Node* getLast(Node* head){
        while( head->next != nullptr) {
            head = head->next;
        }
        return head;
    }
    static Node* flatten(Node* head) {      //for best result take recursion out and return last element
        Node* result = head;
        while (result != nullptr){
            if (result->child){
                Node* branch = flatten(result->child);
                result->child = nullptr;
                Node* branchLast = getLast(branch);
                branchLast->next = result->next;
                if (result->next) { result->next->prev = branchLast;}
                result->next = branch;
                branch->prev = result;
            }
            result = result->next;
        }
        return head;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Node* branch1 = new Node(10);
    branch1->next = new Node(11, branch1, TailTag{});
    branch1->next->next = new Node(12, branch1->next, TailTag{});

    Node* branch2 = new Node(100);
    branch2->next = new Node(200, branch2, TailTag{});
    branch2->next->next = new Node(300, branch2->next, TailTag{});

    Node* main = new Node(1);
    main->next = new Node(2, main, TailTag{});
    main->next->next = new Node(3, main->next, TailTag{});
    main->next->next->next = new Node(4, main->next->next, TailTag{});

    main->next->child = branch1;
    branch1->next->next->child = branch2;
    auto r = Solution::flatten(main);
    return a.exec();
}
