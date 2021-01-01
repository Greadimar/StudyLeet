#ifndef MYLL_H
#define MYLL_H

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
//    QString dbgHead(){
//        QString res = "head: ";
//        Node* temp = head;
//        for (int i = 0; i < size; i++){
//            if (temp != nullptr) res.append(QString::number(temp->val));
//            res.append("; ");
//            temp = head->next;
//        }
//        return res;
//    }

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
                cur = head->next;
            }
        }
        else{
            cur = last;
            while(index++ < size - 1){
                cur = last->prev;
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
#endif // MYLL_H
