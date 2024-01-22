#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void insertattail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

void insertatmiddle(Node* head,int position,int d){
    if(position==1){
        insertAThead()
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    Node* insertdata = new Node(d);
    insertdata->next = temp->next;
    temp->next = insertdata;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertattail(tail,44);
    print(head);
    insertattail(tail,43);
    print(head);
    insertatmiddle(head,2,46);
    print(head);
    
}