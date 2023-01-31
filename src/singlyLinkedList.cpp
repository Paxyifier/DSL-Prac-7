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
        }
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->setNext(newNode);   
    }
    void insertAtFront(int data){
        this->head = new Node(data, this->head);
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
                newNode->setNext(temp);
                temp->setNext(newNode);
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
                temp->setNext(temp->next->next);  
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
        while (temp->next->next != NULL){
            temp=temp->next;
        }
        deletedData = temp->next->data;
        free(temp->next);
        temp->setNext(temp->next->next);
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
        cout << "\nLinked List Elements: ";
        while(temp->next != NULL){
            cout << temp->data ;
            temp=temp->next;
            if (temp->next != NULL){
                cout << " -> ";
            }
        }
        cout<<endl;
    }
    void reverse(){
        Node *cur, *prev, *next;
        cur = this->head;
        while(cur->next != NULL){
            next = cur->next;
            cur->setNext(prev);
            prev = cur;
            cur = next;
        }
        this->head = prev;
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