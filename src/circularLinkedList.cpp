#include <iostream>
using namespace std;
class Node{
    protected:
    public:
    Node *next;
    int data;
    Node(int data, Node *next=NULL){
        this->data = data;
        this->next = next;
    }
};
class CircularLinkedList{
    protected:
    Node *head;
    public:
    CircularLinkedList(){
        this->head = NULL;
    }
    void insertAtEnd(int data){
        Node *temp=this->head, *newNode = new Node(data);
        if (this->head ==NULL){
            this->head = newNode;
            this->head->next = this->head;
            return;
        }
        while (temp->next != this->head) {
            temp = temp->next;
        }
        newNode->next = this->head;
        temp->next = newNode;   
    }
    void insertAtStart(int data){
        Node *temp=this->head, *newNode = new Node(data);
        if (this->head ==NULL){
            this->head = newNode;
            this->head->next = this->head;
            return;
        }
        while (temp->next != this->head) {
            temp = temp->next;
        }
        newNode->next = this->head;
        temp->next = newNode;
        this->head = newNode;
    }
    bool insertAt(int data, int pos){
        if (pos == 0 ) {
            insertAtStart(data);
            return true;
        }
        Node *temp=this->head, *newNode = new Node(data);
        int iter = 0;
        do {
            iter++;
            temp = temp->next;
            if (iter == pos){
                newNode->next = temp->next;
                temp->next = newNode;
                return true;
            }
        }while (temp->next != this->head->next && pos>iter );
        return false;
    }
    int removeFrom(int pos){
        Node *deletedNode = NULL, *temp = this->head;
        int iter=0, deletedData=0;
        if (pos==0){
            return removeFromStart();
        }
        while (temp->next != this->head && pos>iter){
            iter++;
            if (pos==iter){
                deletedData = temp->next->data;
                deletedNode = temp->next;
                temp->next = temp->next->next;  
                // free(deletedNode);
                return deletedData; 
            }
            temp=temp->next;
        }
        return -1;
    }
    int removeFromStart(){
        int deletedData ;
        Node *temp = this->head;
        if (this->head != NULL){
            while (temp->next != this->head) {
                temp = temp->next;
            }
            deletedData= this->head->data;
            this->head = this->head->next;
            temp->next = this->head;
            return deletedData;
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
        while (temp->next->next != this->head){
            temp=temp->next;
        }
        deletedNode = temp->next;
        deletedData = deletedNode->data;
        temp->next = this->head;
        free(deletedNode);
        return deletedData;
    }
    int count(){
        Node *temp = this->head;
        int count = 0;
        while(temp->next != this->head){
            count++;
            temp = temp->next;
        }
        return count+1;
    }
    void print(){
        Node *temp = this->head;
        cout << "Circular Linked List Elements: ";
        do{
            cout << temp->data << " ->";
            temp = temp->next;
        }while(temp != this->head);
        cout << endl;
    }
    void reverse(){
        Node *cur = this->head, *prev = NULL, *next = NULL;
        do{
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }while(cur != this->head);
        cur->next = prev;
        this->head = prev;
        // Node *cur, *prev, *next;
        // cur = this->head;
        // while(cur->next != this->head){
        //     next = cur->next;
        //     cur->next = (prev);
        //     prev = cur;
        //     cur = next;
        // }
        // this->head = prev;
    }
    int search(int q){
        Node *temp = this->head;
        while(temp->next != this->head){
            if (q == temp->data){
                return temp->data;
            }
            temp = temp->next;
        }
        return -1;
    }
};
int main(){
    CircularLinkedList *list = new CircularLinkedList();
    bool run = true;
    int choice, data, pos;
    while (run){
        cout << "1. Insert At End"<<endl;
        cout << "2. Insert At Start"<<endl;
        cout << "3. Insert At"<<endl;
        cout << "4. Remove From End"<<endl;
        cout << "5. Remove From Start"<<endl;
        cout << "6. Remove From"<<endl;
        cout << "7. Count"<<endl;
        cout << "8. Print"<<endl;
        cout << "9. Reverse"<<endl;
        cout << "10. Search"<<endl;
        cout << "11. Exit"<<endl;
        cout << "";
        cout << "Enter Choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter Data: ";
                cin >> data;
                list->insertAtEnd(data);
                break;
            case 2:
                cout << "Enter Data: ";
                cin >> data;
                list->insertAtStart(data);
                break;
            case 3:
                cout << "Enter Data: ";
                cin >> data;
                cout << "Enter Position: ";
                cin >> pos;
                if (list->insertAt(data, pos)){
                    cout << "Inserted Successfully"<<endl;
                }
                else{
                    cout << "Insertion Failed"<<endl;
                }
                break;
            case 4:
                data = list->removeFromEnd();
                if (data == -1){
                    cout << "Deletion Failed"<<endl;
                }
                else{
                    cout << "Deleted Data: " << data <<endl;
                }
                break;
            case 5:
                data = list->removeFromStart();
                if (data == -1){
                    cout << "Deletion Failed"<<endl;
                }
                else{
                    cout << "Deleted Data: " << data <<endl;
                }
                break;
            case 6:
                cout << "Enter Position: ";
                cin >> pos;
                data = list->removeFrom(pos);
                if (data == -1){
                    cout << "Deletion Failed"<<endl;
                }
                else{
                    cout << "Deleted Data: " << data <<endl;
                }
                break;
            case 7:
                cout << "Count: " << list->count() << endl;
                break;
            case 8:
                list->print();
                break;
            case 9:
                list->reverse();
                break;
            case 10:
                cout << "Enter Data: ";
                cin >> data;
                if (list->search(data) == -1){
                    cout << "Not Found"<<endl;
                }
                else{
                    cout << "Found"<<endl;
                }
                break;
            case 11:
                run = false;
                break;
        }
    }
    return 0;
}