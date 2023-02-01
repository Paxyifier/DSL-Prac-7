#include <cstddef>
#include <iostream>
using namespace std;
struct Node{
    public:
    Node *next, *prev;
    int data;

};

class DoublyLinkedList{
    protected:
    Node *head=NULL;
    public:
    void insertAtEnd(int data){
        Node *temp=this->head, *newNode = new Node();
        newNode->data = data;
        if (this->head == NULL){
            this->head = newNode;
            return;
        }
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    bool insertAt(int data, int pos){
        Node *temp=this->head, *newNode = new Node();
        newNode->data = data;
        int iter = 0;
        if (this->head == NULL){
            this->head = newNode;
            return true;
        }
        if (pos == 0){
            insertAtStart(data);
        }
        while (temp->next != NULL && iter<pos){
            iter++;
            if (iter == pos){
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                newNode->next->prev = newNode;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void insertAtStart(int data){
        Node *newNode = new Node();
        newNode->data = data;
        if (this->head == NULL){
            this->head = newNode;
            return;
        }
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }
    bool removeFrom(int pos){
        Node *temp = this->head;
        int iter = 0;
        if (this->head == NULL){
            return false;
        }
        if (pos == 0){
            removeFromStart();
        }
        while (temp->next != NULL && iter<pos){
            iter++;
            if (iter == pos){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    bool removeFromStart(){
        Node *temp = this->head;
        if (this->head == NULL){
            return false;
        }
        this->head = this->head->next;
        this->head->prev = NULL;
        free(temp);
        return true;
    }
    bool removeFromEnd(){
        Node *temp = this->head;
        if (this->head == NULL){
            return false;
        }
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        return true;
    }
    int count(){
        Node *temp = this->head;
        int count = 0;
        while (temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
    void print(){
        Node *temp = this->head;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverse(){
        Node *temp = this->head, *temp2;
        while (temp != NULL){
            temp2 = temp->next;
            temp->next = temp->prev;
            temp->prev = temp2;
            temp = temp2;
        }
        temp = this->head;
        this->head = NULL;
        while (temp != NULL){
            this->head = temp;
            temp = temp->prev;
        }
    }
    bool search(int data){
        Node *temp = this->head;
        while (temp != NULL){
            if (temp->data == data){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
int main(){
    DoublyLinkedList *list = new DoublyLinkedList();
    bool run = true;
    int choice, data, pos;
    while (run){
        cout << "1. Insert at end\n2. Insert at start\n3. Insert at position\n4. Delete from start\n5. Delete from end\n6. Delete from position\n7. Count\n8. Print\n9. Reverse\n10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:
                cout << "Enter data: ";
                cin >> data;
                list->insertAtEnd(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                list->insertAt(data, 0);
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter position: ";
                cin >> pos;
                list->insertAt(data, pos);
                break;
            case 4:
                list->removeFromStart();
                break;
            case 5:
                list->removeFromEnd();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                list->removeFrom(pos);
                break;
            case 7:
                cout << "Number of elements in List: " << list->count() << endl;
                break;
            case 8:
                list->print();
                break;
            case 9:
                list->reverse();
                break;
            case 10:
                run = false;
                break;
            default:
                cout << "Invalid Choice!!" << endl;
                break;
        }
    }
    return 0;
}