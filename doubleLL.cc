#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev ;
    Node* next ;

    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        while(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory if free of data : "<<value<<endl;
    }
};
void insertathead(Node* &head , Node* &tail , int d){
    if(head == NULL){
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertattail(Node* &tail ,Node* &head , int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        temp->next = tail;
        tail = temp;
        head = temp;
    }else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void inmiddle(Node* &head , Node* &tail , int position , int d){
    if(position == 1){
        insertathead(head,tail,d);
        return ;
    }
    else{
        Node* temp = head;
        int cnt = 1;
        while(cnt<position-1){
            cnt++;
            temp = temp->next;
        }

        Node* newnode = new Node(d);
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
        temp->next = newnode;


    }
}
void del(Node* &head,int position){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }else{
        Node* prev = NULL;
        Node* curr = head;

        int cnt =1;
        while(cnt<position){
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
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" " <<endl;
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head,tail,22);
    insertathead(head,tail,21);
    insertathead(head,tail,20);
    insertattail(tail,head,29);
    inmiddle(head,tail,2,199);
    print(head);
    del(head,2);
    print(head);
}
