#include <iostream>
using namespace std;
class Node{
    public:
    Node *next;
    int data;
    Node(int data, Node *next=NULL){
        this->data = data;
        this->next = next;
    }
    Node* getNext(){
        return this->next;
    }
    int getData(){
        return this->data;
    }
    void setNext(Node *next){
        this->next = next;
    }
    bool hasNext(){
        return this->next !=NULL;
    }
};
class LinkedList{
    protected:
    Node *head;
    public:
    LinkedList(){
        this->head = NULL;
    }
    void insertAtEnd(int data){
        Node *temp=this->head, *newNode = new Node(data);
        if (this->head ==NULL){
            this->head = newNode;
            return;
        }
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;   
    }
    void insertAtStart(int data){
        Node *newNode= new Node(data, this->head);
        this->head = newNode;
    }
    bool insertAt(int data, int pos){
        Node *temp=this->head, *newNode = new Node(data);
        if (pos == 0 ) {
            this->head = newNode;
            return true;
        }
        int iter = 0;
        while (temp->next != NULL && pos>iter ) {
            iter++;
            if (iter == pos){
                newNode->next = temp->next;
                temp->next = newNode;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    int removeFrom(int pos){
        Node *temp = this->head, *deletedNode = NULL;
        int deletedData = 0;
        if (this->head == NULL){
            cout << "List is Empty"<<endl;
            return -1;
        }
        if (pos == 0){
            return removeFromStart();
        }
        int iter = 0;
        while (temp->next != NULL && pos>iter){
            iter++;
            if (iter == pos){
                deletedData = temp->next->data;
                deletedNode = temp->next;
                temp->next = temp->next->next;
                free(deletedNode);
                return deletedData;
            }
            temp = temp->next;
        }
        return -1;
    }
    int removeFromStart(){
        Node *deletedNode = NULL;
        int deletedData = 0;
        if (this->head == NULL){
            cout << "List is Empty"<<endl;
            return -1;
        }
        deletedData = this->head->data;
        deletedNode = this->head;
        this->head = this->head->next;
        free(deletedNode);
        return deletedData;
    }
    int removeFromEnd(){
        Node *temp = this->head, *deletedNode = NULL;
        int deletedData = 0;
        if (this->head == NULL){
            cout << "List is Empty"<<endl;
            return -1;
        }
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        deletedData = temp->next->data;
        deletedNode = temp->next;
        temp->next = NULL;
        free(deletedNode);
        return deletedData;
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
        cout << "Linked List Elements: ";
        while(temp != NULL){
            cout << temp->data ;
            temp = temp->next;
            if (temp != NULL){
                cout << " -> ";
            } 
        }
        cout << endl;
    }
    void reverse(){
        Node *temp = this->head, *prev = NULL, *next = NULL;
        while(temp != NULL){
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        this->head = prev;
    }
    int search(int q){
        Node *temp = this->head;
        int pos = 0;
        while(temp != NULL){
            if (temp->data == q){
                return pos;
            }
            pos++;
            temp = temp->next;
        }
        return -1;
    }
};

int main(){    
    LinkedList listTest = LinkedList();
    bool run = true;
    int choice, input, pos;
    LinkedList list;
    while (run) {
        cout << "Singly Linked List Program"<<endl;
        cout << "1.\tInsert at front"<<endl;
        cout << "2.\tInsert at end"<<endl;
        cout << "3.\tInsert at specific position"<<endl;
        cout << "4.\tDelete from front"<<endl;
        cout << "5.\tDelete from end"<<endl;
        cout << "6.\tDelete from specific position"<<endl;
        cout << "7.\tSearch"<<endl;
        cout << "8.\tReverse"<<endl;
        cout << "9.\tPrint"<<endl;
        cout << "10.\tExit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the element to be inserted: ";
                cin >> input;
                list.insertAtStart(input);
                break;
            case 2:
                cout << "Enter the element to be inserted: ";
                cin >> input;
                list.insertAtEnd(input);
                break;
            case 3:
                cout << "Enter the element to be inserted: ";
                cin >> input;
                cout << "Enter the position: ";
                cin >> pos;
                if (list.insertAt(input, pos)){
                    cout << "Element inserted successfully"<<endl;
                }else{
                    cout << "Element not inserted"<<endl;
                }
                break;
            case 4:
                if (list.removeFromStart() != -1){
                    cout << "Element deleted successfully"<<endl;
                }else{
                    cout << "Element not deleted"<<endl;
                }
                break;
            case 5:
                if (list.removeFromEnd() != -1){
                    cout << "Element deleted successfully"<<endl;
                }else{
                    cout << "Element not deleted"<<endl;
                }
                break;
            case 6:
                cout << "Enter the position: ";
                cin >> pos;
                if (list.removeFrom(pos) != -1){
                    cout << "Element deleted successfully"<<endl;
                }else{
                    cout << "Element not deleted"<<endl;
                }
                break;
            case 7:
                cout << "Enter the element to be searched: ";
                cin >> input;
                pos = list.search(input);
                if ( pos!= -1){
                    cout << "Element found at "<<pos<<endl;
                }else{
                    cout << "Element not found"<<endl;
                }
                break;
            case 8:
                list.reverse();
                cout << "List reversed successfully"<<endl;
                break;
            case 9:
                list.print();
                break;
            case 10:
                run = false;
                break;
            default:
                cout << "Invalid choice"<<endl;
                break;
        }
    }
    return 0;
}