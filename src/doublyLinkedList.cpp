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
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return;
    }
    bool insertAt(int data, int pos){
        Node *temp=this->head, *newNode = new Node();
        newNode->data = data;
        int iter = 0;
        if(this->head ==NULL && pos !=0){
            cout << "Linked List is Empty!!"<<endl;
            return false;
        }
        if (pos==0) {
            this->head->prev = newNode;
            newNode->next = this->head;
            this->head = newNode;
            return true;
        }
        while (temp->next != NULL && iter<pos) {
            iter++;
            if (iter == pos){
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
                return true;
            }
            temp->next = temp;
        }
        return false;
    }
    void insertAtStart(int data){
        Node *temp=this->head, *newNode = new Node();
        newNode->data = data;
        if (this->head == NULL){
            this->head = newNode;
            return;
        }
        this->head->prev = newNode;
        newNode->next = this->head;
        this->head = newNode;
    }
    bool removeFrom(int pos){
        Node *temp=this->head;
        int iter = 0;
        if(this->head ==NULL && pos !=0){
            cout << "Linked List is Empty!!"<<endl;
            return false;
        }
        if (pos==0) {
            this->head->next->prev = NULL;
            this->head = this->head->next;
        }
        while (temp->next != NULL && iter<pos) {
            iter++;
            if (iter == pos){
                temp->next->prev = temp->prev;
                temp->prev = temp->next;
                free(temp);
                return true;
            }
            temp->next = temp;
        }
        return false;
    }
    bool removeFromStart(){
        Node *temp = this->head;
        if (this->head == NULL)
        {
            return false;
        }
        else if (this->head != NULL) {
            this->head = this->head->next;
            this->head->prev = NULL;
            free(temp);
            return true;
        } else return false;
    }
    bool removeFromEnd(){
        Node *temp = this->head;
        while (temp->next != NULL){
            temp=temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        return true;
    }
    int count(){
        Node *temp = this->head;
        int count = 0;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        return count+1;
    }
    void print(){
        Node *temp = this->head;
        cout << "\nDoubly Linked List Elements: ";
        do{
            cout << temp->data << " ->";
            temp = temp->next;
        }while(temp != NULL);
        cout << endl;
    }
    void reverse(){
        Node *temp = this->head, *cur=this->head;
        while (cur != NULL){
        // while (cur->next == NULL){
            cur->prev = cur->next;
            cur->next = temp;
            cur=cur->prev;
        }
    }
    bool search(int data){
        Node *temp = this->head;
        while (temp->next != NULL){
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
    // write code to test all functions of DoublyLinkedList class
    DoublyLinkedList listTest =  DoublyLinkedList();
    listTest.insertAtStart(1);
    listTest.print();
    listTest.insertAtStart(2);
    listTest.print();
    listTest.insertAtEnd(3);
    listTest.print();
    cout << boolalpha <<listTest.insertAt(7, 2)<<endl;
    listTest.print();
    cout << "removing from position 2: " << listTest.removeFrom(2) << endl;
    cout << "removing from position 0: " << listTest.removeFromStart() << endl;
    cout << "removing from end: " << listTest.removeFromEnd() << endl;
    listTest.insertAtStart(2);
    listTest.insertAtEnd(3);
    listTest.insertAtStart(4);
    listTest.insertAtEnd(5);
    listTest.insertAtEnd(6);
    listTest.print();
    cout << "reversing the list" << endl;
    listTest.reverse();
    listTest.print();
    cout << "Element found: " << listTest.search(5) << endl;
    cout << "Element found: " << listTest.search(7) << endl;
    bool run = false;
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