#include<iostream>
using namespace std;
class Node{
    public:
    Node* head;
    Node* tail;
    int data;
    Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            this->next = NULL;
            delete this->next;
        }
        cout<<" memory is free of value : "<<value<<endl;
    }
    
};
void insertathead(Node* &head , Node* &tail ,int d){
    if(head == NULL){
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}
void insertattail(Node* &tail , Node* &head , int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        temp->next = tail;
        tail = temp;
        head = temp; 
    }else{
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}
void inmiddle(Node* &head , Node* &tail , int position , int d){
    if(position == 1){
        insertathead(head,tail,d);
        return ;
    }
    Node* temp = head;
    int cnt =1;
    while(cnt < position-1){
        cnt++;
        temp = temp->next;
    }

    Node* newnode = new Node(d);
        newnode->next = temp->next;
        temp->next = newnode;

    if(temp->next == NULL){
        insertattail(tail,head,d);
        return;
    }
}
void deleting(Node* &head , Node* &tail , int position){
    if(position == 1){
       Node* temp = head;
       head = temp->next;
       temp->next = NULL;
       delete temp;
    }else{
        Node* prev = NULL;
        Node* curr = head;
        int cnt = 1;
    while( cnt < position ){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void print(Node* &head){
    Node*  temp = head;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,34);
    insertattail(tail,head,33);
    inmiddle(head,tail,2,11);
    print(head);
    deleting(head,tail,1);
    print (head);

}