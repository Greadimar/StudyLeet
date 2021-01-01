#ifndef BEST_H
#define BEST_H
class DoublyListNode {
public:
    int value;
    DoublyListNode *next, *prev;

    explicit DoublyListNode(int value) {
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    DoublyListNode *head;
    DoublyListNode *tail;
    int size;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    [[nodiscard]] int get(int index) const {
        if (index >= size) {
            return -1;
        }

        DoublyListNode *current;
        if (index < size / 2) {
            current = head;
            for (; index > 0; --index) {
                current = current->next;
            }
        } else {
            current = tail;
            for (index = size - 1 - index; index > 0; --index) {
                current = current->prev;
            }
        }

        return current->value;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    bool addAtHead(int val) {
        auto *newHead = new DoublyListNode(val);

        if (size == 0) {
            head = newHead;
            tail = newHead;
        } else {
            head->prev = newHead;
            newHead->next = head;
            head = newHead;
        }

        size++;
        return true;
    }

    /** Append a node of value val to the last element of the linked list. */
    bool addAtTail(int val) {
        auto *newTail = new DoublyListNode(val);

        if (size == 0) {
            tail = newTail;
            head = newTail;
        } else {
            tail->next = newTail;
            newTail->prev = tail;
            tail = newTail;
        }

        size++;
        return true;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    bool addAtIndex(int index, int val) {
        if (index > size) {
            return false;
        }

        if (index == size) {
            return addAtTail(val);
        }

        if (size == 0 || index == 0) {
            return addAtHead(val);
        }

        DoublyListNode *current;
        if (index < size / 2) {
            current = head;
            while (index > 0) {
                current = current->next;
                index--;
            }
        } else {
            current = tail;
            index = size - 1 - index;
            while (index > 0) {
                current = current->prev;
                index--;
            }
        }

        auto *newNode = new DoublyListNode(val);
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        size++;
        return true;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    bool deleteAtIndex(int index) {
        if (size == 0) {
            return false;
        }

        if (index >= size) {
            return false;
        }

        if (index == 0) {
            head->prev = nullptr;
            head = head->next;
            size--;
            return true;
        }

        if (index == size - 1) {
            tail = tail->prev;
            tail->next->prev = nullptr;
            tail->next = nullptr;
            size--;
            return true;
        }

        DoublyListNode *current;
        if (index < size / 2) {
            current = head;
            while (index > 0) {
                current = current->next;
                index--;
            }
        } else {
            current = tail;
            index = size - 1 - index;
            while (index > 0) {
                current = current->prev;
                index--;
            }
        }

        current->prev->next = current->next;
        current->prev->next->prev = current->prev;
        current->next = nullptr;
        current->prev = nullptr;
        size--;
        return true;
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
#endif // BEST_H
