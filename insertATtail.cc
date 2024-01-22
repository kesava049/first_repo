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
void insertATtail(Node* tail,int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp = tail;
}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertATtail(tail,34);
    print(head);
}
