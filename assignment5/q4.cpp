#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=nullptr;
    }
};
void insertatend(Node*& head,int val){
    Node* newNode=new Node(val);
    if(head==nullptr){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
}
void display(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data;
        if(temp->next!=nullptr) cout<<"->";
        temp=temp->next;
    }
    cout<<"->NULL"<<endl;
}
Node* reverseList(Node* head){
    Node* prev=nullptr;
    Node* curr=head;
    Node* next=nullptr;
    while(curr!=nullptr){
        next=curr->next;     
        curr->next=prev;     
        prev=curr;           
        curr=next;           
    }
    return prev;
}
int main(){
    Node* head=nullptr;
    insertatend(head,1);
    insertatend(head,2);
    insertatend(head,3);
    insertatend(head,4);
    cout<<"Original List: ";
    display(head);
    head=reverseList(head);
    cout<<"Reversed List: ";
    display(head);
    return 0;
}