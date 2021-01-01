#include <QCoreApplication>
#include <unordered_map>
class Node {
public:
   // Node(Node& n): val(n.val)
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
//    void operator = (Node& n){
//        val = n.val;
//        next
//    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* oldIt = head;
        if (!oldIt) return  nullptr;
        Node* copy = new Node(head->val);
        Node* copyHead = copy;
        copy->random = (head->random);
        while (oldIt->next != nullptr){
            copy->next = new Node(oldIt->next->val);
            copy->next->random = oldIt->next->random;
            oldIt = oldIt->next;
            copy = copy->next;
        }
        Node* cur = copyHead;
        while (cur != nullptr){
            if (cur->random){
                Node* itCopy = copyHead;
                oldIt = head;
                while (oldIt != cur->random){
                    itCopy = itCopy->next;
                    oldIt = oldIt->next;
                }
                cur->random = itCopy;
            }
            cur = cur->next;
        }
        return copyHead;
    }
    Node* copyRandomListFast(Node* head) {
         if(head==NULL) return NULL;

         Node *start=NULL,*last=NULL;
         Node *ptr1=head;
         std::vector<Node*> v;
         while(ptr1){
             v.push_back(ptr1->next);
             ptr1=ptr1->next;
         }

         ptr1=head;
         while(ptr1){
             Node *newnode = new Node(ptr1->val);
             if(start==NULL)
             {
                 start=newnode;
                 last=newnode;
             }
             else{
                 last->next=newnode;
                 last=newnode;
             }
             ptr1=ptr1->next;
         }
         //cout << "h1" << endl;
         ptr1=head;
         Node *fast=NULL;
         Node *ptr2=start;
         while(ptr1 && ptr2){
             fast=ptr1->next;
             ptr1->next=ptr2;
             ptr2->random=ptr1;
             ptr1=fast;
             ptr2=ptr2->next;
         }
         //cout << "h2" << endl;
         ptr2=start;
         while(ptr2){
             if(ptr2->random && ptr2->random->random)
                 ptr2->random=ptr2->random->random->next;
             else if(ptr2->random->random==NULL)
                 ptr2->random=NULL;
             ptr2=ptr2->next;
         }
         ptr1=head;
         for(int i=0; i<v.size(); i++){
             ptr1->next=v[i];
             ptr1=ptr1->next;
         }
         return start;
     }

      Node* getClone(Node* old, std::unordered_map<Node*, Node*>     &visited) {
           return visited[old] = visited.count(old)? visited[old]: new Node(old->val);
       }

      Node* copyRandomListBest(Node* head) {
           if (!head)                      return NULL;
           std::unordered_map<Node*, Node*>     visited;

           Node* cur = head;
           while (cur) {
               getClone(cur, visited);
               if (cur->next)     visited[cur]->next = getClone(cur->next, visited);
               if (cur->random)   visited[cur]->random = getClone(cur->random, visited);
               cur         = cur->next;
           }  return visited[head];
       }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
