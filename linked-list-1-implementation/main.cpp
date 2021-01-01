#include <QCoreApplication>
#include <QDebug>
struct HeadTag{};
struct TailTag{};
struct Node {

    int val;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int v):val(v) {};
    Node(int v, Node* n, Node* p):val(v), next(n), prev(p) {};
    Node(int v, Node* n, HeadTag):val(v), next(n) {};
    Node(int v, Node* p, TailTag):val(v), prev(p) {};
};

class MyLinkedList {

private:
    Node* head = nullptr;
    Node* last = nullptr;   //last element. real tail is nullptr
    int size;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
    }
    ~MyLinkedList(){
            Node* cur = head;
            while (size > 0){
                Node* temp = nullptr;
                if (cur != nullptr){
                    temp = cur->next;
                    delete cur;
                }
                cur= temp;
                size --;
            }
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size || index < 0) return -1;
        Node* cur = head;

        if ((index + index) < size){
            while(index--){
                cur = cur->next;
            }
        }
        else{
            cur = last;
            while(index++ < size - 1){
                cur = cur->prev;
            }
        }
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        head = new Node(val, head, HeadTag());
        size ++;
        if (size == 1){
            last = head;
        }
        if (head->next != nullptr) head->next->prev = head;

//        else if (size == 2){
//            tail = head->next;
//        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        size ++;
        last = new Node(val, last, TailTag{});

        if (size == 1){
            head = last;
            head->next = last;
        }
        if (last->prev != nullptr) last->prev->next = last;

//        else if (size == 2){
//            head = tail->prev;
//        }
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if ((index < 0) || (index > size)) return;
        if (index == 0){ addAtHead(val); return;}
        if (index == size) { addAtTail(val); return;}
        Node* cur = head;

        if ((index + index) < size){
            while(index--){
                cur = cur->next;
            }
        }
        else{
            cur = last;
            while(index++ < size - 1){
                cur = cur->prev;
            }
        }
        Node* newNode = new Node(val, cur, cur->prev);
        cur->prev->next = newNode;
        cur->prev = newNode;
        size++;

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if ((index < 0) || (index >= size)) return;
        Node* cur = head;
        if ((index + index) < size){
            while(index--){
                cur = cur->next;
            }
        }
        else{
            cur = last;
            while(index++ < size - 1){
                cur = cur->prev;
            }
        }
        if (cur == nullptr) return;
        if (last == cur) last = nullptr;
        if (head == cur) head = nullptr;

        if (cur->prev != nullptr){
            if (last == nullptr) last = cur->prev;
            cur->prev->next = cur->next;
        }
        if (cur->next != nullptr){
            if (head == nullptr) head = cur->next;
            cur->next->prev = cur->prev;
        }
        delete cur;
        size--;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyLinkedList* ll = new MyLinkedList();
    ll->addAtHead(2);     //2
    ll->deleteAtIndex(1);    // 2
    ll->addAtHead(2);    // 2 2
    ll->addAtHead(7); // 7 2 2
    ll->addAtHead(3); // 3 7 2 2
    ll->addAtHead(2); // 2 3 7 2 2
    ll->addAtHead(5); // 5 2 3 7 2 2
        ll->addAtTail(5); // 5 2 3 7 2 2 5
    qDebug() << ll->get(5); //  2
    ll->deleteAtIndex(6); // 5 2 3 7 2 2
        ll->deleteAtIndex(4); // 5 2 3 7 2


    delete ll;
//        ["MyLinkedList","addAtHead","deleteAtIndex","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtTail","get","deleteAtIndex","deleteAtIndex"]
//        [[],[2],[1],[2],[7],[3],[2],[5],[5],[5],[6],[4]]
    MyLinkedList l;
    l.addAtHead(38);
        l.addAtTail(66);
    l.addAtTail(61); //38 66 61
    l.addAtTail(76);
    l.addAtTail(26);
    l.addAtTail(37);
    l.addAtTail(8); // 38 66 61 76 26 37 8;
    l.deleteAtIndex(5); // 38 66 61 76 26 8;
    l.addAtHead(4); // 4 38 66 61 76 26 8;
    l.addAtHead(45); // 45 4 38 66 61 76 26 8;
    qDebug() << "get 1" << l.get(4);
    l.addAtTail(85); // 45 4 38 66 61 76 26 8; 85
    l.addAtHead(37); //37 45 4 38 66 61 76 26 8; 85
    qDebug() << "get 2" << l.get(5);
    l.addAtTail(93);  //37 45 4 38 66 61 76 26 8; 85 93
    l.addAtIndex(10, 23);
    l.addAtTail(21);  //37 45 4 38 66 61 76 26 8; 85 23 93 21
    l.addAtHead(52); //52 37 45 4 38 66 61 76 26 8; 85 23 93 21
    l.addAtHead(15); //15 52 37 45 4 38 66 61 76 26 8; 85 23 93 21
    l.addAtHead(47);//47 15 52 37 45 4 38 66 61 76 26 8;85 23 93 21
    qDebug() << "get3 " << l.get(12);
    l.addAtIndex(6,24); //47 15 37 52 45 4 24 38 66 61 76 26 8; 85 23 93 21
    l.addAtHead(64); //64 47 15 37 52 45 4 38 66 61 76 26 8; 85 23 93 21
    qDebug() << "get4" << l.get(4);
//        ["MyLinkedList","addAtHead 38","addAtTail 66","addAtTail 61","addAtTail 76","addAtTail+26","addAtTail+ 37","addAtTail+8",
    //"deleteAtIndex 5"+,"addAtHead 4","addAtHead 45","get 4","addAtTail 85","addAtHead 37","get 5","addAtTail","addAtIndex","addAtTail","addAtHead",
      //"addAtHead","addAtHead","get","addAtIndex","addAtHead","get","addAtHead","deleteAtIndex","addAtHead","addAtTail","addAtTail","addAtIndex","addAtTail","addAtHead","get","addAtTail","deleteAtIndex","addAtIndex","deleteAtIndex","addAtHead","addAtTail","addAtHead","addAtHead","addAtTail","addAtTail","get","get","addAtHead","addAtTail","addAtTail","addAtTail","addAtIndex","get","addAtHead","addAtIndex","addAtHead","addAtTail","addAtTail","addAtIndex","deleteAtIndex","addAtIndex","addAtHead","addAtHead","deleteAtIndex","addAtTail","deleteAtIndex","addAtIndex","addAtTail","addAtHead","get","addAtIndex","addAtTail","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","addAtHead","deleteAtIndex","get","get","addAtHead","get","addAtTail","addAtTail","addAtIndex","addAtIndex","addAtHead","addAtTail","addAtTail","get","addAtIndex","addAtHead","deleteAtIndex","addAtTail","get","addAtHead","get","addAtHead","deleteAtIndex","get","addAtTail","addAtTail"]
//        [[],[38+],[66]+,[61+],[76+],[26+],[37+],[8+],[5],[4],[45],[4],[85],[37],[5],[93],[10,23],[21],[52],[15],[47],[12],[6,24],[64],[4],[31],[6],[40],[17],[15],[19,2],[11],[86],[17],[55],[15],[14,95],[22],[66],[95],[8],[47],[23],[39],[30],[27],[0],[99],[45],[4],[9,11],[6],[81],[18,32],[20],[13],[42],[37,91],[36],[10,37],[96],[57],[20],[89],[18],[41,5],[23],[75],[7],[25,51],[48],[46],[29],[85],[82],[6],[38],[14],[1],[12],[42],[42],[83],[13],[14,20],[17,34],[36],[58],[2],[38],[33,59],[37],[15],[64],[56],[0],[40],[92],[63],[35],[62],[32]]

    MyLinkedList* myLinkedList = new MyLinkedList();
    //    myLinkedList->addAtHead(7);
    //    myLinkedList->addAtHead(2);
    //    myLinkedList->addAtHead(1);;
    myLinkedList->addAtTail(3);
    //    myLinkedList->addAtIndex(0, 10);    // linked list becomes 10
    //        myLinkedList->addAtIndex(0, 20);    // linked list becomes
    //                myLinkedList->addAtIndex(1, 30);    // linked list becomes 1->2->3
    //    myLinkedList->deleteAtIndex(2);
    //    myLinkedList->addAtHead(6);
    //    myLinkedList->addAtTail(4);
    myLinkedList->get(0);              // return 2
    // myLinkedList->deleteAtIndex(1);    // now the linked list is 1->3
    qDebug() << myLinkedList->get(4);              // return 3
    delete myLinkedList;
    return a.exec();
}
