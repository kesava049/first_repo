#include<iostream>
#include<algorithm>
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
void insertAThead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertATtail(Node* &tail,int d){
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
void insertATmiddle(Node* &head,Node* &tail,int position,int d){
    if(position==1){
        insertAThead(head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertATtail(tail,d);
        return;
    }

    Node* newnode = new Node(d);
    newnode->next = temp->next;
    temp->next = newnode;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAThead(head,43);
    insertAThead(head,11);
    print(head);
    insertATmiddle(head,tail,4,90);
    print(head);
    cout<<"head="<<head->data<<endl;
    cout<<"tail="<<tail->data<<endl;
}