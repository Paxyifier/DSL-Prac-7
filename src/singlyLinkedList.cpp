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
        Node *deletedNode = NULL, *temp = this->head;
        int iter=0, deletedData=0;
        if (pos==0){
            deletedData = this->head->data;
            free(temp);
            this->head = this->head->next;
            return deletedData;
        }
        while (temp->next != NULL && pos>iter){
            iter++;
            if (pos==iter){
                deletedData = temp->next->data;
                free(temp->next);
                temp->next =(temp->next->next);  
                return deletedData; 
            }
            temp=temp->next;
        }
        return -1;
    }
    int removeFromStart(){
        int deletedData ;
        if (this->head != NULL){
            deletedData= this->head->data;
            this->head = this->head->next;
        }
        cout << "List is Empty"<<endl;
        return -1;
    }
    int removeFromEnd(){
        Node *deletedNode = NULL, *temp = this->head;
        int deletedData=0;
        if (this->head == NULL){
            cout << "List is Empty"<<endl;
            return -1;
        }
        while (temp->next != NULL){
            temp=temp->next;
            if (temp->next == NULL){
                deletedData = temp->data;
                free(temp);
                temp->next = NULL;
                return deletedData;
            }
        }
        return -1;
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
        cout << "\nLinked List Elements: ";
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
        Node *prev = NULL, *current = this->head, *next = NULL;
        while (current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        this->head = prev;
        
        // Node *cur, *prev, *next;
        // cur = this->head;
        // while(cur->next != NULL){
        //     next = cur->next;
        //     cur->next =(prev);
        //     prev = cur;
        //     cur = next;
        // }
        // this->head = prev;
    }
    int search(int q){
        Node *temp = this->head;
        while(temp->next != NULL){
            if (q == temp->data){
                return temp->data;
            }
            temp = temp->next;
        }
        return -1;
    }
};

int main(){    LinkedList listTest = LinkedList();
    listTest.insertAtStart(1);
    listTest.insertAtStart(2);
    listTest.insertAtEnd(3);
    listTest.insertAt(7, 2);
    listTest.print();
    cout << "removing from position 2: " << listTest.removeFrom(2) << endl;
    cout << "removing from position 0: " << listTest.removeFromStart() << endl;
    cout << "removing from end: " << listTest.removeFromEnd() << endl;
    cout << "removing from position 5: " << listTest.removeFrom(5) << endl;
    cout << "removing from position 1: " << listTest.removeFromStart() << endl;
    cout << "removing from end: " << listTest.removeFromEnd() << endl;
    cout << "removing from position 1: " << listTest.removeFromStart() << endl;
    cout << "removing from end: " << listTest.removeFromEnd() << endl;
    cout << "removing from position 1: " << listTest.removeFromStart() << endl;
    cout << "removing from end: " << listTest.removeFromEnd() << endl;
    listTest.insertAtStart(1);
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
                if (list.search(input) != -1){
                    cout << "Element found"<<endl;
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