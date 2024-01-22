#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    ~Node(){
        int value = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
    }
};
void insert(Node* &tail , int element , int d){
    if(tail == NULL){
        Node* newnode = new Node(d);
        newnode->next = tail;
        tail = newnode;
        newnode->next = newnode;
    }else{
        Node* curr = tail;
        while(curr->data!=element){
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node* &tail){
    Node* temp = tail;
    if(tail == NULL){
        cout<<"the list is empty please check again "<<" ";
        return ;
    }else{
        
        do{
            cout<<tail->data<<endl;
            tail = tail->next;
        }while(tail!=temp);
    }
    cout<<endl;
}
void deletion(Node* &tail , int value){
    if(tail == NULL){
        cout<<"the list empty please check the shit " << " ";
        return ; 
    }else{
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if(curr == prev){
            tail = NULL;
        }
        else if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main(){
    Node* tail = NULL;
    insert(tail,4,2);
    print(tail);
    insert(tail,2,6);
    print(tail);
    deletion(tail,2);
    print(tail);
}