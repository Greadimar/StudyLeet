#ifndef FIRSTIMPLEMENTATION_H
#define FIRSTIMPLEMENTATION_H


struct Node{
    Node(int val): val(val) {}
    int val;
    Node* next = nullptr;
    Node* previous = nullptr;
};

class MyLinkedList {
    Node* head = nullptr;
    Node* tail = nullptr;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {

    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int idx = 0;
        Node* it = head;
        while (idx < index && it != nullptr){
            it = it->next;
            idx ++;
        }
        if (it != nullptr)
            return it->val;
        else return 0;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (head == nullptr){
            head = new Node{val};
            tail = head->next;
        }
        else{
            head->previous = new Node{val};
            head->previous->next = head;
            head = head->previous;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* last;
        Node* it = head;
        while (it != nullptr){
            last = it;
            it = it->next;
        }

        Node* newNode = new Node(val);
        if (head == nullptr) head = newNode;
        else{
            last->next = newNode;
            newNode->previous = last;
        }

    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int idx = 0;
        Node* it = head;
        Node* last = (head != nullptr)? head->previous : nullptr;
        while (idx < index && it != nullptr){
            last = it;
            it = it->next;
            idx ++;
        }
        if (it != nullptr){
            Node* oldNode = it;
            Node* newNode = new Node(val);
            newNode->next = oldNode;
            newNode->previous = it->previous;
            oldNode->previous = newNode;

            if (head == oldNode) head = newNode;
            else newNode->previous->next = newNode;
        }
        else if (idx == index){
            Node* newNode = new Node(val);
            if (head == nullptr) head = newNode;
            else{
                last->next = newNode;
                newNode->previous = last;
            }
        }

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int idx = 0;
        Node* it = head;
        while (idx < index && it != nullptr){
            it = it->next;
            idx ++;
        }
        if (it != nullptr){
            if (it->previous != nullptr){
                it->previous->next = it->next;
                if (it->next != nullptr) {
                    it->next->previous = it->previous;
                }
            }
            else {
                if (it->next != nullptr){
                    it->next->previous = nullptr;
                }
            }
            if (head == it) head = it->next;;
            delete it;
        }
    }
};
#endif // FIRSTIMPLEMENTATION_H
