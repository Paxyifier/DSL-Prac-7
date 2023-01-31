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
    void insert(int data){
        Node *temp=this->head, *newNode = new Node();
        newNode->data = data;
        if (this->head != NULL){
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
        }
        while (temp->next != NULL && iter<pos) {
            temp->next = temp;
            iter++;
        }
        if (iter == pos){
            temp->next->prev = newNode;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            return true;
        }
        return false;
    }
    bool deleteAt(int pos){
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
        Node *temp = this->head, *cur=this->head;
        while (cur != NULL){
        // while (cur->next == NULL){
            cur->prev = cur->next;
            cur->next = temp;
            cur=cur->prev;
        }
    }
};