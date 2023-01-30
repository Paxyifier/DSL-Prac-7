#include <iostream>

class Node{
    protected:
    Node *next;
    int data;
    public:
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
        if ((this->head ==NULL)){
            this->head = newNode;
        }
        while (temp->hasNext()) {
            temp = temp->getNext();
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
        while (temp->hasNext() && pos>iter ) {
            iter++;
            if (iter == pos){
                newNode->setNext(temp);
                temp->setNext(newNode);
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }
    int removeFrom(int pos){
        Node *deletedNode = NULL, *temp = this->head;
        int iter=0, deletedData=0;
        if (pos==0){
            deletedData = this->head->getData();
            free(temp);
            this->head = this->head->getNext();
            return deletedData;
        }
        while (temp->hasNext() && pos>iter){
            iter++;
            if (pos==iter){
                deletedData = temp->getNext()->getData();
                free(temp->getNext());
                temp->setNext(temp->getNext()->getNext());  
                return deletedData; 
            }
            temp=temp->getNext();
        }
        return -1;
    }
    int removeFromStart(){
        if (this->head != NULL){
            this->head = this->head->getNext();
        }
        cout << "List is Empty"<<endl;
    }
    int removeFromEnd(){
        Node *deletedNode = NULL, *temp = this->head;
        int deletedData=0;
        if (this->head == NULL){
            cout << "List is Empty"<<endl;
        }
        while (temp->hasNext()->hasNext()){
            temp=temp->getNext();
        }
        deletedData = temp->getNext()->getData();
        free(temp->getNext());
        temp->setNext(temp->getNext()->getNext());
    }
    int count(){
        Node *temp = this->head;
        int count = 0;
        while(temp->hasNext()){
            count++;
            temp = temp->getNext();
        }
        return count+1;
    }
    void print(){
        Node *temp = this->head;
        cout << "\nLinked List Elements: "
        while(temp->hasNext()){
            cout << temp->getData() ;
            temp=temp->getNext();
            if (!temp->hasNext()){
                cout << " -> ";
            }
        }
        cout<<endl;
    }
};