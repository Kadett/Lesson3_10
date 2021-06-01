#include <iostream>

class ListInt{
    struct Node{
        int data;
        Node *next;
    };
    Node *head;
    int size;
public:
    ListInt() : head(nullptr), size(0) {}
    void insert(int data){
        Node *n = new Node();
        n->data = data;
        n->next = nullptr;

        Node *current = head;
        if(current == nullptr) {
            head = n;
            size++;
        } else {
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = n;
            size++;
        }
    }

    void removeAt(int index){
        if(index == 0){
            Node *tmp = head;
            head = head->next;
            delete tmp;
            size--;
        } else {
            Node *previous = this->head;
            for (int i = 0; i < index; ++i) {
                previous = previous->next;
            }
            Node *toDel = previous->next;
            previous->next = toDel->next;
            delete toDel;
            size--;
        }

    }

    int& operator[](const int index){
        int count = 0;
        Node *curr = this->head;
        while (curr != nullptr){
            if(count == index){
                break;
            }
            curr = curr->next;
            count++;
        }
        return curr->data;
    }

    int getSize(){
        return size;
    }

};